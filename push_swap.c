/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:03:08 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/12 21:51:47 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static char	*normalise_tabs(const char *arg)
{
	char	*dup;
	int		i;

	i = 0;
	if (arg == NULL)
		return (NULL);
	dup = ft_strdup(arg);
	if (dup == NULL)
		return (NULL);
	while (dup[i])
	{
		if (dup[i] >= 9 && dup[i] <= 13)
			dup[i] = ' ';
		i++;
	}
	return (dup);
}

static void	verify_args(t_node **a, t_node **b, char **parts)
{
	t_node	*n;
	int		v;
	int		j;

	j = 0;
	while (parts[j] != NULL)
	{
		if (atoi_overflow(parts[j], &v, *a) == 1)
		{
			free_split(parts);
			exit_and_free(a, b);
		}
		n = new_node(v);
		if (n == NULL)
		{
			free_split(parts);
			exit_and_free(a, b);
		}
		add_back(a, n);
		j++;
	}
}

static char	**split_args(const char *arg, t_node **a, t_node **b)
{
	char	*tmp;
	char	**parts;

	tmp = normalise_tabs(arg);
	if (tmp == NULL)
		exit_and_free(a, b);
	parts = ft_split(tmp, ' ');
	free(tmp);
	if (parts == NULL)
		exit_and_free(a, b);
	if (parts[0] == NULL)
	{
		free_split(parts);
		exit_and_free(a, b);
	}
	return (parts);
}

/* new_node, ft_split, ft_strdup need to be freed */
int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;
	char	**parts;
	int		i;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	i = 1;
	while (i < argc)
	{
		parts = split_args(argv[i], &a, &b);
		verify_args(&a, &b, parts);
		free_split(parts);
		i++;
	}
	if (is_sorted(a))
	{
		if (a != NULL)
			free_stack(&a);
		if (b != NULL)
			free_stack(&b);
	}
	return (0);
}

// /* Helper to visualise in Terminal */
// void print_list(const char *label, t_node *head)
// {
// 	t_node *p = head;

// 	printf("%s", label);
// 	while (p)
// 	{
// 		printf("%d", p->value);
// 		if (p->next) printf(" -> ");
// 		p = p->next;
// 	}
// 	printf("\n");
// }

// int main(void)
// {
// 	t_node *a = NULL;
// 	t_node *b = NULL;

// 	t_node *n1 = new_node(10);
// 	t_node *n2 = new_node(20);
// 	t_node *n3 = new_node(30);
// 	t_node *n4 = new_node(40);
// 	t_node *n5 = new_node(100);
// 	t_node *n6 = new_node(200);
// 	t_node *n7 = new_node(300);
// 	t_node *n8 = new_node(400);
// 	a = n1;
// 	n1->next = n2;
// 	n2->next = n3;
// 	n3->next = n4;
// 	n4->next = NULL;

// 	b = n5;
// 	n5->next = n6;
// 	n6->next = n7;
// 	n7->next = n8;
// 	n8->next = NULL;

// 	print_list("A before: ", a);
// 	print_list("B before: ", b);

// 	pa(&a, &b);
// 	pb(&a, &b);
// 	sa(&a);
// 	sb(&b);
// 	ss(&a, &b);
// 	ra(&a);
// 	rb(&b);
// 	rr(&a, &b);
// 	rra(&a);
// 	rrb(&b);
// 	 rrr(&a, &b);
// 	print_list("A after : ", a);
// 	print_list("B after : ", b);
// 	free_stack(&a);
// 	free_stack(&b);

// 	return 0;
// }
