/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:06:38 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/04 21:44:01 by mzangaro         ###   ########.fr       */
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

void	sa(t_node **a)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (a == NULL || *a == NULL || (*a)->next == NULL)
		return ;
	first = *a;
	second = first->next;
	third = second->next;

	second->next = first;
	first->next = third;
	*a = second;
	ft_printf("sa\n");
}
