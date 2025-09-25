/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/24 23:30:21 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/25 04:49:42 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	init_chunk_aux(t_chunk *ck, int len, int width)
{
	ck->len = 0;
	ck->width = 0;
	ck->prev_soft = 0;
	ck->low = -1;
	ck->high = -1;
	ck->soft = -1;
	if (len <= 0 || width <= 0)
		return (0);
	return (1);
}

void	chunk_recalc_from_low(t_chunk *ck)
{
	long	pct;

	if (!ck || ck->len <= 0 || ck->width <= 0 || ck->low < 0)
		return ;
	ck->high = ck->low + ck->width - 1;
	if (ck->high > ck->len - 1)
		ck->high = ck->len - 1;
	pct = ((long)ck->width * (long)ck->prev_soft) / (long)100;
	ck->soft = ck->low + (int)pct - 1;
	if (ck->soft < ck->low)
		ck->soft = ck->low;
	if (ck->soft > ck->high)
		ck->soft = ck->high;
	if (ck->soft > ck->len - 1)
		ck->soft = ck->len - 1;
}

int	chunk_advance(t_chunk *ck)
{
	if (!ck || ck->len <= 0)
		return (0);
	ck->low = ck->high + 1;
	if (ck->low > ck->len - 1)
		return (0);
	chunk_recalc_from_low(ck);
	return (1);
}

int	init_chunk(t_chunk *ck, int len, int width, int prev_soft)
{
	if (!ck)
		return (0);
	if (init_chunk_aux(ck, len, width) != 1)
		return (0);
	if (prev_soft < 0)
		prev_soft = 0;
	else if (prev_soft > 100)
		prev_soft = 100;
	ck->len = len;
	ck->width = width;
	ck->prev_soft = prev_soft;
	ck->low = 0;
	chunk_recalc_from_low(ck);
	return (1);
}
