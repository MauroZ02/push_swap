/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 16:54:45 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/27 20:37:29 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	aux_overflow(const char *str, int *out_i, int *out_sign)
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

/* after checking the sign of the number; checks if it fits the max & min,
	 and converts to int */
int	overflow(const char *str, int *v)
{
	int					i;
	int					sign;
	unsigned long long	acc;
	unsigned long long	limit;

	if (str == NULL || v == NULL || aux_overflow(str, &i, &sign) != 1)
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
	*v = (int)((long long)acc * (long long)sign);
	return (1);
}

/* has_space may be redundant... but we still keep it so far */
int	atoi_overflow(const char *str, int *v, t_node *a)
{
	if (has_space(str) != 0)
		return (1);
	if (is_digit(str) != 1)
		return (1);
	if (overflow(str, v) != 1)
		return (1);
	if (has_duplicate(a, *v) == 1)
		return (1);
	return (0);
}
