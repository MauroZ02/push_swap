/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:03:08 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/23 22:40:38 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	verify_args(char **parts, t_node **a, t_node **b)
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

static char	*only_space(const char *arg)
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

static char	**split_args(const char *arg, t_node **a, t_node **b)
{
	char	*tmp;
	char	**parts;

	tmp = only_space(arg);
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
		verify_args(parts, &a, &b);
		free_split(parts);
		i++;
	}
	if (a == NULL)
		return (0);
	assign_index(a);
	if (is_sorted(a))
	{
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	sort_stack(&a, &b);
	if (is_sorted(a))
	{
		free_stack(&a);
		free_stack(&b);
		return (0);
	}
	free_stack(&a);
	free_stack(&b);
	return (0);
}
