/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:06:38 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/06 19:24:49 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_node **a, t_node **b)
{
	t_node	*n;

	n = remove_at_top(a);
	if (n)
	{
		add_at_top(b, n);
		ft_printf("pb\n");
	}
}

void	pa(t_node **a, t_node **b)
{
	t_node	*n;

	n = remove_at_top(b);
	if (n)
	{
		add_at_top(a, n);
		ft_printf("pa\n");
	}
}

static void	swap_top(t_node **s)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (s == NULL || *s == NULL || (*s)->next == NULL)
		return ;
	first = *s;
	second = first->next;
	third = second->next;

	second->next = first;
	first->next = third;
	*s = second;
}

void	sa(t_node **a)
{
	swap_top(a);
	ft_printf("sa\n");
}

void	sb(t_node **b)
{
	swap_top(b);
	ft_printf("sb\n");
}

void	ss(t_node **a, t_node **b)
{
	swap_top(a);
	swap_top(b);
	ft_printf("ss\n");
}
