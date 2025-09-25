/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:16:14 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/24 23:18:25 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*remove_front(t_node **top)
{
	t_node	*first;
	t_node	*next;

	if (top == NULL || *top == NULL)
		return (NULL);
	first = *top;
	next = first->next;
	*top = next;
	first->next = NULL;
	return (first);
}

void	add_front(t_node **top, t_node *n)
{
	if (top == NULL || n == NULL)
		return ;
	n->next = *top;
	*top = n;
}

void	pb(t_node **a, t_node **b)
{
	t_node	*n;

	n = remove_front(a);
	if (n)
	{
		add_front(b, n);
		ft_printf("pb\n");
	}
}

void	pa(t_node **a, t_node **b)
{
	t_node	*n;

	n = remove_front(b);
	if (n)
	{
		add_front(a, n);
		ft_printf("pa\n");
	}
}
