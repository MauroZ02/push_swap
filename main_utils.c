/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 04:57:34 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/25 04:59:21 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	verify_args(char **parts, t_node **a, t_node **b)
{
	t_node	*n;
	int		v;
	int		j;

	j = 0;
	while (parts[j] != NULL)
	{
		if (atoi_overflow(parts[j], &v, *a) == 1)
		{
			free_split(parts);
			exit_and_free(a, b);
		}
		n = new_node(v);
		if (n == NULL)
		{
			free_split(parts);
			exit_and_free(a, b);
		}
		add_back(a, n);
		j++;
	}
}

char	*only_space(const char *arg)
{
	char	*dup;
	int		i;

	i = 0;
	if (arg == NULL)
		return (NULL);
	dup = ft_strdup(arg);
	if (dup == NULL)
		return (NULL);
	while (dup[i])
	{
		if (dup[i] >= 9 && dup[i] <= 13)
			dup[i] = ' ';
		i++;
	}
	return (dup);
}

char	**split_args(const char *arg, t_node **a, t_node **b)
{
	char	*tmp;
	char	**parts;

	tmp = only_space(arg);
	if (tmp == NULL)
		exit_and_free(a, b);
	parts = ft_split(tmp, ' ');
	free(tmp);
	if (parts == NULL)
		exit_and_free(a, b);
	if (parts[0] == NULL)
	{
		free_split(parts);
		exit_and_free(a, b);
	}
	return (parts);
}
