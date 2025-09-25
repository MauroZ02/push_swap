/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:23:30 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/25 04:00:07 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	has_space(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i])
	{
		if (str[i] == ' ' || str[i] == '\t')
			return (1);
		i++;
	}
	return (0);
}

int	has_duplicate(t_node *a, int v)
{
	t_node	*curr;

	curr = a;
	while (curr != NULL)
	{
		if (curr->value == v)
			return (1);
		curr = curr->next;
	}
	return (0);
}

int	is_digit(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
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