/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/21 21:39:07 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/27 20:35:07 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* counts how many numbers are smaller than this*/
int	count_smaller(t_node *head, int value)
{
	t_node	*current;
	int		count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		if (current->value < value)
			count++;
		current = current->next;
	}
	return (count);
}

/* assigns the number of "how many smaller numbers has" to each number */
void	assign_index(t_node *a)
{
	t_node	*current;

	current = a;
	while (current != NULL)
	{
		current->i = count_smaller(a, current->value);
		current = current->next;
	}
}

/* finds index 0 -the number that has 0 smaller numbers- */
int	find_smaller_index(t_node *a)
{
	t_node	*current;
	int		pos;
	int		best_pos;
	int		smaller_index;

	current = a;
	pos = 0;
	best_pos = 0;
	smaller_index = current->i;
	while (current != NULL)
	{
		if (current->i < smaller_index)
		{
			smaller_index = current->i;
			best_pos = pos;
		}
		current = current->next;
		pos++;
	}
	return (best_pos);
}

/* leads the index 0 to the top */
void	smaller_to_top(t_node **a, int pos)
{
	int	len;
	int	i;

	if (a == NULL || *a == NULL)
		return ;
	len = stack_len(*a);
	if (pos <= (len / 2))
	{
		while (pos > 0)
		{
			ra(a);
			pos--;
		}
	}
	else
	{
		i = len - pos;
		while (i > 0)
		{
			rra(a);
			i--;
		}
	}
}
