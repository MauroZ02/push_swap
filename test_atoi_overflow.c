#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
/* ---- Minimal types & helpers ---- */

typedef struct s_node
{
	int             value;
	struct s_node  *next;
}   t_node;

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
int	aux_overflow(const char *str, int *out_i, int *out_sign)
{
	int	i;
	int	sign;

	if (str == NULL || out_i == NULL || out_sign == NULL)
		return (0);
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	*out_i = i;
	*out_sign = sign;
	return (1);
}

int	overflow(const char *str, int *out)
{
	int					i;
	int					sign;
	unsigned long long	acc;
	unsigned long long	limit;

	if (str == NULL || out == NULL || aux_overflow(str, &i, &sign) != 1)
		return (0);
	acc = 0;
	limit = (unsigned long long)INT_MAX;
	if (sign < 0)
		limit = (unsigned long long)(-(long long)INT_MIN);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		acc = acc * 10 + (unsigned long long)(str[i] - '0');
		if (acc > limit)
			return (0);
		i++;
	}
	*out = (int)((long long)acc * (long long)sign);
	return (1);
}

int	has_space(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

int	is_digit(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	has_duplicate(t_node *a, int v)
{
	t_node	*curr;

	curr = a;
	while (curr != NULL)
	{
		if (curr->value == v)
			return (1);
		curr = curr->next;
	}
	return (0);
}

static void putstr(const char *s)
{
	size_t i;

	if (!s) return;
	i = 0;
	while (s[i] != '\0')
		i++;
	/* i is length */
	write(1, s, (unsigned int)i);
}

static void putnbr(int n)
{
	char buf[12];
	long x;
	int  i;

	x = n;
	i = 0;
	if (x == 0)
	{
		write(1, "0", 1);
		return ;
	}
	if (x < 0)
	{
		write(1, "-", 1);
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
		write(1, &buf[i], 1);
	}
}

t_node	*new_node(int value)
{
	t_node	*n;

	n = ft_calloc(1, sizeof(*n));
	if (n == NULL)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

void	add_front(t_node **top, t_node *n)
{
	if (top == NULL || n == NULL)
		return ;
	n->next = *top;
	*top = n;
}

void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

/* ---- Your function under test (prototype only) ---- */
int	atoi_overflow(const char *str, int *out, t_node *a)
{
	if (has_space(str) != 0) 
		return (1);
	if (is_digit(str) != 1)
		return (1);
	if (overflow(str, out) != 1)
		return (1);
	if (has_duplicate(a, *out) == 1)
		return (1);
	return (0);
}

/* ---- Drive a single test ---- */
static void run_case(const char *label, const char *input, t_node **a)
{
	int     ok;
	int     v;
	t_node *n;

	(void)label; /* not printed to keep output short; remove cast to show label */
	ok = atoi_overflow(input, &v, *a);
	if (ok == 0)
	{
		/* success -> push into A so later duplicate tests are meaningful */
		n = new_node(v);
		if (!n)
		{
			putstr("alloc fail\n");
			return ;
		}
		add_front(a, n);
		putstr("OK  : \""); putstr(input); putstr("\" -> ");
		putnbr(v); putstr("\n");
	}
	else
	{
		putstr("ERR : \""); putstr(input); putstr("\"\n");
	}
}

/* ---- Main with a curated test set ---- */
int main(void)
{
	t_node      *a;
	/* progressive tests: format, sign, extremes, overflow, garbage, spaces, duplicates */
	const char  *tests[] = {
		"42", "-42", "+43", "0", "0001",
		"2147483647", "-2147483648",   /* INT_MAX / INT_MIN */
		"2147483648", "-2147483649",   /* overflow/underflow -> ERR */
		"+", "-", "--1", "1-2", "12a", " 3", "3 ", "1\t2", "",
		"10", "10",                     /* duplicate on second -> ERR if duplicate check works */
		NULL
	};
	int         i;

	a = NULL;
	i = 0;
	while (tests[i] != NULL)
	{
		run_case("case", tests[i], &a);
		i++;
	}
	free_stack(&a);
	return (0);
}
