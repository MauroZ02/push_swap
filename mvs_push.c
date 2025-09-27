/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mvs_push.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:16:14 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/27 20:44:10 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* deletes the top node */
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

/* assigns the node next to the deleted one as the head */
void	add_front(t_node **top, t_node *n)
{
	if (top == NULL || n == NULL)
		return ;
	n->next = *top;
	*top = n;
}

/* pushes the top node in A to B */
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

/* pushes the top node in B to A */
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
