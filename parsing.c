/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:23:30 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/09 21:46:40 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_putendl_fd("Error\n", 2);
	exit(1);
}

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

int	aux_atoi(const char *str, int *out_i, int *out_sign)
{
	int	i;
	int	sign;

	if (str == NULL || out_i == NULL || out_sign == NULL)
		return (0);
	i = 0;
	sign = 1;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (str[i] == '\0')
		return (0);
	*out_i = i;
	*out_sign = sign;
	return (1);
}

int	atoi_overflow(const char *str, int *out)
{
	int					i;
	int					sign;
	unsigned long long	acc;
	unsigned long long	limit;

	if (str == NULL || out == NULL || aux_atoi(str, &i, &sign) != 1)
		return (0);
	acc = 0;
	limit = (unsigned long long)INT_MAX;
	if (sign < 0)
		limit = (unsigned long long)(-(long long)INT_MIN);
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		acc = acc * 10 + (unsigned long long)(str[i] - '0');
		if (acc > limit)
			return (0);
		i++;
	}
	*out = (int)((long long)acc * (long long)sign);
	return (1);
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
