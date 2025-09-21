/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:39:07 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/21 21:47:03 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_smaller(t_node *head, int value)
{
	t_node	*current;
	int		count;

	current = head;
	count = 0;
	while (current->next != NULL)
	{
		if (current->value < value)
			count++;
		current = current->next;
	}
	return (count);
}

void	assign_index(t_node *a)
{
	t_node	*current;

	current = a;
	while (current->next != NULL)
	{
		current->i = count_smaller(a, current->value);
		current = current->next;
	}
}