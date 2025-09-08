/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 16:37:28 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/08 19:29:28 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_down(t_node **stack)
{
	t_node	*prev;
	t_node	*last;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	prev = *stack;
	while (prev->next->next != NULL)
		prev = prev->next;
	last = prev->next;
	prev->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rra(t_node **a)
{
	rotate_down(a);
	ft_printf("rra\n");
}

void	rrb(t_node **b)
{
	rotate_down(b);
	ft_printf("rrb\n");
}

void	rrr(t_node **a, t_node **b)
{
	rotate_down(a);
	rotate_down(b);
	ft_printf("rrr\n");
}
