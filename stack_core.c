/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_core.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:15:27 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/12 18:03:53 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*new_node(int value)
{
	t_node	*n;

	n = ft_calloc(1, sizeof(*n));
	if (n == NULL)
		return (NULL);
	n->value = value;
	n->next = NULL;
	return (n);
}

t_node	*last_node(t_node *a)
{
	t_node	*last;

	if (a == NULL)
		return (NULL);
	last = a;
	while (last->next != NULL)
		last = last->next;
	return (last);
}

int	stack_len(t_node *stack)
{
	int		i;

	if (stack == NULL)
		return (0);
	i = 0;
	while (stack != NULL)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

int	is_sorted(t_node *stack)
{
	t_node	*next;

	if (stack == NULL)
		return (1);
	next = stack->next;
	while (next != NULL)
	{
		if (stack->value >= next->value)
			return (0);
		stack = stack->next;
		next = next->next;
	}
	return (1);
}
