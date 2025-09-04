/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_0.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 18:16:14 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/04 21:07:27 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*node_new(int value)
{
	t_node	*n;

	n = ft_calloc(1, sizeof(*n));
	if (n == NULL)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

void	add_at_top(t_node **top, t_node *n)
{
	if (n == NULL)
		return (NULL);
	n->next = *top;
	*top = n;
}

t_node	*remove_at_top(t_node **top)
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
