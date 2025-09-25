/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 21:06:38 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/08 20:08:58 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap_top(t_node **stack)
{
	t_node	*first;
	t_node	*second;
	t_node	*third;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	third = second->next;
	second->next = first;
	first->next = third;
	*stack = second;
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
