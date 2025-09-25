/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 02:19:50 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/25 05:34:05 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* --------------------------- MIO ------------------------------------------ */

void	phase_one(t_node **a, t_node **b, int width, int prev_soft)
{
	t_chunk	ck;
	int		pos;

	if (!a || !*a || init_chunk(&ck, stack_len(*a), width, prev_soft) != 1)
		return ;
	while (*a)
	{
		pos = pos_in_chunk(*a, ck.high);
		if (pos == -1)
		{
			if (chunk_advance(&ck) != 1)
				break ;
		}
		else
		{
			pos_to_top_a(a, pos);
			push_and_organise(a, b, &ck);
		}
	}
}

void	phase_two(t_node **a, t_node **b) 
{
	int max;
	int pos;

	while (*b != NULL)
	{
		max = find_max_index(*b);
		pos = pos_index(*b, max);
		if (pos == -1)
			break;
		/* Rotar B mínima distancia para poner max arriba */
		pos_to_top_b(b, pos);   // ver cambio 2)
		pa(a, b);
		/* Colocar el mayor recién subido al fondo de A para construir ascendente */
	}
}

void	k_sort(t_node **a, t_node **b) 
{
	int	len;
	int	width;
	int	prev_soft;

	if (a == NULL || *a == NULL)
		return ;
	len = stack_len(*a);
	if (len <= 5 || is_sorted(*a))
		return ;
	if (len <= 100)
		width = len / 5;
	else
		width = len / 11;
	if (width < 1)
		width = 1;
	prev_soft = 66;
	phase_one(a, b, width, prev_soft);
	phase_two(a, b);
}
