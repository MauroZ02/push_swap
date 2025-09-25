/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 14:51:10 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/08 19:29:33 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	rotate_up(t_node **stack)
{
	t_node	*first;
	t_node	*new_top;
	t_node	*tail;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	new_top = first->next;
	tail = new_top;
	while (tail->next != NULL)
		tail = tail->next;
	tail->next = first;
	first->next = NULL;
	*stack = new_top;
}

void	ra(t_node **a)
{
	rotate_up(a);
	ft_printf("ra\n");
}

void	rb(t_node **b)
{
	rotate_up(b);
	ft_printf("rb\n");
}

void	rr(t_node **a, t_node **b)
{
	rotate_up(a);
	rotate_up(b);
	ft_printf("rr\n");
}
