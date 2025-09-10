/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:16:14 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/10 20:31:15 by mzangaro         ###   ########.fr       */
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

void	add_back(t_node **a, t_node *n)
{
	t_node	*last;

	if (a == NULL || n == NULL)
		return ;
	if (*a == NULL)
	{
		n->next = NULL;
		*a = n;
		return ;
	}
	last = *a;
	while (last->next != NULL)
		last = last->next;
	n->next = NULL;
	last->next = n;
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
