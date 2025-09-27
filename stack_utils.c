/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 20:15:27 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/27 20:38:23 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* creates the node and assigns its value */
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

/* adds the node to the back of the stack */
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

void	free_stack(t_node **stack)
{
	t_node	*temp;

	if (stack == NULL)
		return ;
	while (*stack != NULL)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
	*stack = NULL;
}

void	exit_and_free(t_node **a, t_node **b)
{
	free_stack(a);
	free_stack(b);
	ft_putendl_fd("Error", 2);
	exit(1);
}
