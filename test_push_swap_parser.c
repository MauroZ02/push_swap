/* test_push_swap_parser.c */
/* Standalone tester that reads tokens from argv, splits once, and validates them.
   It expects your own implementations (linked) of:
     - int  is_digit(const char *str);           // 1 ok, 0 bad (optional sign + digits only)
     - int  overflow(const char *str, int *out); // 1 ok, 0 bad (INT_MIN..INT_MAX)
     - int  has_duplicate(struct s_node *a, int v); // 1 dup exists, 0 no dup
   It provides a minimal stack and split logic. */

#include <unistd.h>
#include <stdlib.h>

/* ---------- Minimal stack ---------- */
typedef struct s_node
{
	int             value;
	struct s_node  *next;
}   t_node;

static void	putstr_fd(const char *s, int fd)
{
	size_t i;

	if (!s)
		return ;
	i = 0;
	while (s[i] != '\0')
		i++;
	write(fd, s, (unsigned int)i);
}

static void	putnbr_fd(int n, int fd)
{
	char buf[12];
	long x;
	int  i;

	x = n;
	i = 0;
	if (x == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (x < 0)
	{
		write(fd, "-", 1);
		x = -x;
	}
	while (x > 0)
	{
		buf[i++] = (char)('0' + (x % 10));
		x /= 10;
	}
	while (i > 0)
	{
		i--;
		write(fd, &buf[i], 1);
	}
}

static t_node	*new_node(int v)
{
	t_node	*n;

	n = (t_node *)malloc(sizeof(*n));
	if (!n)
		return (NULL);
	n->value = v;
	n->next = NULL;
	return (n);
}

static void	add_front(t_node **top, t_node *n)
{
	if (!top || !n)
		return ;
	n->next = *top;
	*top = n;
}

static void	free_stack(t_node **stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = *stack;
		*stack = (*stack)->next;
		free(tmp);
	}
}

void	*ft_calloc(size_t n, size_t size)
{
	unsigned char	*ptr;
	size_t			i;

	i = 0;
	ptr = malloc(n * size);
	if (ptr == NULL)
		return (NULL);
	while (i < n * size)
	{
		ptr[i] = 0;
		i++;
	}
	return ((void *)ptr);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
	write(fd, "\n", 1);
}

/* ---------- Your parser functions (prototypes only; link your .o/.a) ---------- */
int	is_digit(const char *str);           /* 1 ok, 0 bad */
int	overflow(const char *str, int *out); /* 1 ok, 0 bad */
int	has_duplicate(t_node *a, int v);     /* 1 dup exists, 0 no dup */

/* ---------- Tiny dynamic array of tokens ---------- */
typedef struct s_vec
{
	char	**v;
	int		len;
	int		cap;
}	t_vec;

static char	*ps_strndup(const char *s, int n)
{
	char	*p;
	int		i;

	p = (char *)malloc((unsigned int)n + 1);
	if (!p)
		return (NULL);
	i = 0;
	while (i < n)
	{
		p[i] = s[i];
		i++;
	}
	p[n] = '\0';
	return (p);
}

static int	vec_init(t_vec *vec, int cap)
{
	vec->v = (char **)malloc(sizeof(char *) * (unsigned int)cap);
	if (!vec->v)
		return (0);
	vec->len = 0;
	vec->cap = cap;
	return (1);
}

static int	vec_push(t_vec *vec, char *s)
{
	char	**nv;
	int		newcap;
	int		i;

	if (vec->len < vec->cap)
	{
		vec->v[vec->len++] = s;
		return (1);
	}
	newcap = vec->cap * 2;
	nv = (char **)malloc(sizeof(char *) * (unsigned int)newcap);
	if (!nv)
		return (0);
	i = 0;
	while (i < vec->len)
	{
		nv[i] = vec->v[i];
		i++;
	}
	free(vec->v);
	vec->v = nv;
	vec->cap = newcap;
	vec->v[vec->len++] = s;
	return (1);
}

static void	vec_free(t_vec *vec)
{
	int	i;

	if (!vec || !vec->v)
		return ;
	i = 0;
	while (i < vec->len)
	{
		free(vec->v[i]);
		i++;
	}
	free(vec->v);
	vec->v = NULL;
	vec->len = 0;
	vec->cap = 0;
}

/* Split once over all argv[i], on spaces/tabs only. */
static int	split_argv_tokens(int argc, char **argv, t_vec *out_tokens)
{
	int	i;
	int	j;
	int	start;

	if (!vec_init(out_tokens, 16))
		return (0);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '\t')
			j++;
		while (argv[i][j] != '\0')
		{
			start = j;
			while (argv[i][j] != '\0' && argv[i][j] != ' ' && argv[i][j] != '\t')
				j++;
			if (j > start)
			{
				char *tok = ps_strndup(argv[i] + start, j - start);
				if (!tok || !vec_push(out_tokens, tok))
				{
					free(tok);
					vec_free(out_tokens);
					return (0);
				}
			}
			while (argv[i][j] == ' ' || argv[i][j] == '\t')
				j++;
		}
		i++;
	}
	return (1);
}

/* ---------- Run the pipeline and explain the error cause ---------- */
static void	run_pipeline(const char *s, t_node **a)
{
	int	val;

	/* 1) format */
	if (is_digit(s) != 1)
	{
		putstr_fd("ERR:format: \"", 1); putstr_fd(s, 1); putstr_fd("\"\n", 1);
		return ;
	}
	/* 2) overflow/underflow */
	if (overflow(s, &val) != 1)
	{
		putstr_fd("ERR:overflow: \"", 1); putstr_fd(s, 1); putstr_fd("\"\n", 1);
		return ;
	}
	/* 3) duplicate in current A */
	if (has_duplicate(*a, val) == 1)
	{
		putstr_fd("ERR:duplicate: \"", 1); putstr_fd(s, 1); putstr_fd("\"\n", 1);
		return ;
	}
	/* success → push into A */
	{
		t_node *n = new_node(val);
		if (!n)
		{
			putstr_fd("ERR:alloc\n", 1);
			return ;
		}
		add_front(a, n);
		putstr_fd("OK : \"", 1); putstr_fd(s, 1); putstr_fd("\" -> ", 1);
		putnbr_fd(val, 1); putstr_fd("\n", 1);
	}
}

int	main(int argc, char **argv)
{
	t_vec	toks;
	t_node	*a;
	int		i;

	if (argc < 2)
		return (0);
	if (!split_argv_tokens(argc, argv, &toks))
	{
		/* allocation failure while tokenising */
		putstr_fd("ERR:split\n", 1);
		return (1);
	}
	a = NULL;
	i = 0;
	while (i < toks.len)
	{
		run_pipeline(toks.v[i], &a);
		i++;
	}
	/* summary (optional) */
	putstr_fd("A size: ", 1);
	{
		int n = 0;
		t_node *p = a;
		while (p) { n++; p = p->next; }
		putnbr_fd(n, 1); putstr_fd("\n", 1);
	}
	free_stack(&a);
	vec_free(&toks);
	return (0);
}
