/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/25 02:19:50 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/25 19:30:22 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* ----------------- PHASE ONE QUE FUNCIONA ---------------------------------*/
// void	phase_one(t_node **a, t_node **b, int width, int prev_soft)
// {
// 	t_chunk	ck;
// 	int		pos;

// 	if (!a || !*a || init_chunk(&ck, stack_len(*a), width, prev_soft) != 1)
// 		return ;
// 	while (*a)
// 	{
// 		pos = pos_in_chunk(*a, ck.high);
// 		if (pos == -1)
// 		{
// 			if (chunk_advance(&ck) != 1)
// 				break ;
// 		}
// 		else
// 		{
// 			pos_to_top_a(a, pos);
// 			push_and_organise(a, b, &ck);
// 		}
// 	}
// }
/* ----------------- PHASE ONE QUE FUNCIONA ---------------------------------*/

/* ----------------- PHASE TWO QUE FUNCIONA ---------------------------------*/
// void	phase_two(t_node **a, t_node **b)
// {
// 	int	max;
// 	int	pos;

// 	while (*b != NULL)
// 	{
// 		max = find_max_index(*b);
// 		pos = pos_index(*b, max);
// 		if (pos == -1)
// 			break ;
// 		/* Rotar B mínima distancia para poner max arriba */
// 		pos_to_top_b(b, pos); // ver cambio 2)
// 		pa(a, b); /* hasta aquí original */
// 	/* Colocar el mayor recién subido al fondo de A para construir ascendente */
// 		// if (*b && (*a)->i - 1 != (*b)->i) /* nuevo <--------- */
// 		// 	ra(a);
// 	}
// }
/* ----------------- PHASE TWO QUE FUNCIONA ---------------------------------*/

/* ----------------- PHASE ONE QUE FUNCIONA ---------------------------------*/
// void    phase_one(t_node **a, t_node **b, int width, int prev_soft)
// {
//     int i;
//     int range;
//     int size;

//     (void)width;
//     (void)prev_soft;
//     if (!a || !*a)
//         return ;
//     size = stack_len(*a);
//     range = 0;
//     while ((range * range) <= size)
//         range++;
//     range--;
//     range = (range * 14) / 10;
//     i = 0;
//     while (*a)
//     {
//         if ((*a)->i <= i)
//         {
//             pb(a, b);
//             i++;
//         }
//         else if ((*a)->i <= i + range)
//         {
//             pb(a, b);
//             i++;
//             if (*a && (*a)->i > i + range)
//                 rr(a, b);
//             else
//                 rb(b);
//         }
//         else
//             ra(a);
//     }
// }
/* ----------------- PHASE ONE QUE FUNCIONA ---------------------------------*/

static void	stratify(t_node **a, t_node **b, int *i, int range)
{
	if ((*a)->i <= (*i))
	{
		pb(a, b);
		(*i)++;
	}
	else if ((*a)->i <= (*i) + range)
	{
		pb(a, b);
		(*i)++;
		if (*a && (*a)->i > (*i) + range)
			rr(a, b);
		else
			rb(b);
	}
	else
		ra(a);
}

void	phase_one(t_node **a, t_node **b)
{
	int	i;
	int	range;
	int	size;

	if (!a || !*a)
		return ;
	size = stack_len(*a);
	range = 0;
	while ((range * range) <= size)
		range++;
	range--;
	range = (range * 14) / 10;
	i = 0;
	while (*a)
	{
		stratify(a, b, &i, range);
	}
}

void	phase_two(t_node **a, t_node **b)
{
	int	max;
	int	pos;

	while (*b)
	{
		max = find_max_index(*b);
		pos = pos_index(*b, max);
		if (pos == -1)
			break ;
		pos_to_top_b(b, pos);
		pa(a, b);
	}
	if (a && *a)
	{
		pos = pos_index(*a, 0);
		if (pos != -1)
			pos_to_top_a(a, pos);
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
	phase_one(a, b);
	phase_two(a, b);
}
