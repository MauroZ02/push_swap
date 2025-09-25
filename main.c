/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:03:08 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/25 05:04:00 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_both(t_node **a, t_node **b)
{
	if (a)
		free_stack(a);
	if (b)
		free_stack(b);
}

static void	build_stack(int argc, char **argv, t_node **a, t_node **b)
{
	int		i;
	char	**parts;

	i = 1;
	while (i < argc)
	{
		parts = split_args(argv[i], a, b);
		verify_args(parts, a, b);
		free_split(parts);
		i++;
	}
}

static int	control_and_assign(t_node **a, t_node **b)
{
	if (*a == NULL)
	{
		free_both(a, b);
		return (1);
	}
	assign_index(*a);
	if (is_sorted(*a))
	{
		free_both(a, b);
		return (1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	build_stack(argc, argv, &a, &b);
	if (a == NULL)
	{
		free_both(&a, &b);
		return (0);
	}
	if (control_and_assign(&a, &b))
		return (0);
	sort_stack(&a, &b);
	free_both(&a, &b);
	return (0);
}
