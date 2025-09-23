/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   k_sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:19:53 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/23 22:42:40 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* it returns the max index value, not its position. (-1) = Error */
int	find_max_index(t_node *stack)
{
	t_node	*current;
	int		max;

	if (stack == NULL)
		return (-1);
	current = stack;
	max = current->i;
	while (current != NULL)
	{
		if (current->i > max)
			max = current->i;
		current = current->next;
	}
	return (max);
}

/* it returns the position of the desired index. (-1) = Error */
int	pos_index(t_node *stack, int index)
{
	t_node	*current;
	int		pos;

	if (stack == NULL)
		return (-1);
	current = stack;
	pos = 0;
	while (current != NULL)
	{
		if (current->i == index)
			return (pos);
		current = current->next;
		pos++;
	}
	return (-1);
}

/* this function scans the stack and finds the suitable index to push either
	 a index in top position, or in bottom position. */
//int	pos_in_chunk(t_node *a, int low, int high)
int	pos_in_chunk(t_node *a, int high)
{
	t_node	*current;
	int		len;
	int		pos;
	int		pos_top;
	int		pos_bottom;

	if (a == NULL)
		return (-1);
	current = a;
	pos = 0;
	pos_top = -1;
	pos_bottom = -1;
	while (current != NULL)
	{
		//if (current->i >= low && current->i <= high)
		if (current->i <= high)
		{
			if (pos_top == -1)
				pos_top = pos;
			pos_bottom = pos;
		}
		current = current->next;
		pos++;
	}
	/* ... tras el bucle que rellena pos_top y pos_bottom ... */
	len = pos;/* pos acumuló el total de nodos */
	if (pos_top == -1)
		return (-1);
	if (pos_top <= (len - pos_bottom))
		return (pos_top);
	return (pos_bottom);
	// if (pos_top > (pos - pos_bottom))
	// 	return (pos_bottom);
	// return (pos_top);
}

void	phase_one(t_node **a, t_node **b, int width, int soft_pct)
{
	int	n;
	int	low;
	int	high;
	int	soft;
	int	p;

	if (*a == NULL)
		return ;
	n = stack_len(*a);
	low = 0;
	high = low + width - 1;
	if (high > n - 1)
		high = n - 1;
	soft = low + (width * soft_pct) / 100 - 1;
	if (soft < high)
		soft = high;
	if (soft > n - 1)
		soft = n - 1;
	while (*a != NULL)
	{
		//p = pos_in_chunk(*a, low, high);
		p = pos_in_chunk(*a, high);
		if (p == -1)
		{
			low = high + 1;
			if (low > n - 1)
				break ;
			high = low + width - 1;
			if (high > n - 1)
				high = n - 1;
			soft = low + (width * soft_pct) / 100 - 1;
			if (soft < high)
				soft = high;
			if (soft > n - 1)
				soft = n - 1;
			continue ;
		}
		if (p <= stack_len(*a) / 2)
			while (p-- > 0)
				ra(a);
		else
		{
			p = stack_len(*a) - p;
			while (p-- > 0)
				rra(a);
		}
		// if ((*a)->i >= low && (*a)->i <= high)
		if ((*a)->i <= high)
		{
			pb(a, b);
			if ((*b)->i - low < (high - low + 1) / 2)
				rb(b);
			low++;
			if (low > high)
			{
				high = low + width - 1;
				if (high > n - 1)
					high = n - 1;
				soft = low + (width * soft_pct) / 100 - 1;
				if (soft < high)
					soft = high;
				if (soft > n - 1)
					soft = n - 1;
			}
		}
		//else if ((*a)->i > high && (*a)->i <= soft)
		//	pb(a, b);
	}
}

// /* this function scans the stack and finds the suitable index to push either
// 	 a index in top position, or in bottom position. */
// int	pos_in_chunk(t_node *a, int low, int high)
// {
// 	t_node	*current;
// 	int		len;
// 	int		pos;
// 	int		pos_top;
// 	int		pos_bottom;

// 	if (a == NULL)
// 		return (-1);
// 	current = a;
// 	pos = 0;
// 	pos_top = -1;
// 	pos_bottom = -1;
// 	while (current != NULL)
// 	{
// 		if (current->i >= low && current->i <= high)
// 		{
// 			if (pos_top == -1)
// 				pos_top = pos;
// 			pos_bottom = pos;
// 		}
// 		current = current->next;
// 		pos++;
// 	}
// 	/* ... tras el bucle que rellena pos_top y pos_bottom ... */
// 	len = pos;                 /* pos acumuló el total de nodos */
// 	if (pos_top == -1)
//     	return (-1);
// 	if (pos_top <= (len - pos_bottom))
//     	return (pos_top);
// 	return (pos_bottom);

// 	// if (pos_top > (pos - pos_bottom))
// 	// 	return (pos_bottom);
// 	// return (pos_top);
// }

// void	phase_one(t_node **a, t_node **b, int width, int soft_pct)
// {
// 	int	n;
// 	int	low;
// 	int	high;
// 	int	soft;
// 	int	p;

// 	if (*a == NULL)
// 		return ;
// 	n = stack_len(*a);
// 	low = 0;
// 	high = low + width - 1;
// 	if (high > n - 1)
// 		high = n - 1;
// 	soft = low + (width * soft_pct) / 100 - 1;
// 	if (soft < high)
// 		soft = high;
// 	if (soft > n - 1)
// 		soft = n - 1;
// 	while (*a != NULL)
// 	{
// 		p = pos_in_chunk(*a, low, high);
// 		if (p == -1)
// 		{
// 			low = high + 1;
// 			if (low > n - 1)
// 				break ;
// 			high = low + width - 1;
// 			if (high > n - 1)
// 				high = n - 1;
// 			soft = low + (width * soft_pct) / 100 - 1;
// 			if (soft < high)
// 				soft = high;
// 			if (soft > n - 1)
// 				soft = n - 1;
// 			continue ;
// 		}
// 		if (p <= stack_len(*a) / 2)
// 			while (p-- > 0)
// 				ra(a);
// 		else
// 		{
// 			p = stack_len(*a) - p;
// 			while (p-- > 0)
// 				rra(a);
// 		}
// 		if ((*a)->i >= low && (*a)->i <= high)
// 		{
// 			pb(a, b);
// 			if ((*b)->i - low < (high - low + 1) / 2)
// 				rb(b);
// 			low++;
// 			if (low > high)
// 			{
// 				high = low + width - 1;
// 				if (high > n - 1)
// 					high = n - 1;
// 				soft = low + (width * soft_pct) / 100 - 1;
// 				if (soft < high)
// 					soft = high;
// 				if (soft > n - 1)
// 					soft = n - 1;
// 			}
// 		}
// 		// else if ((*a)->i > high && (*a)->i <= soft)
// 		// 	pb(a, b);
// 	}
// }

// void	phase_one(t_node **a, t_node **b, int width, int prev_soft)
// {
// 	int	high;
// 	int	low;
// 	int	soft;
// 	int	len;
// 	int	pos;

// 	low = 0;
// 	len = stack_len(*a);
// 	high = low + width - 1;
// 	soft = low + (width * prev_soft)/100 - 1;
// 	while (*a != NULL)
// 	{
// 		pos = pos_in_chunk(*a, low, high);
// 		if (pos == -1)
// 		{
// 			low = high + 1;
// 			if (low > len - 1)
// 				break ;
// 		}
// 		if (pos != -1)
// 		{
// 			if (pos <= len / 2)
// 				ra(a);
// 			else 
// 				rra(a);
// 		}
// 		if (low <= )
// 	}
// }

void	phase_two(t_node **a, t_node **b)
{
	int	m;
	int	p;
	int	len;
	int	steps;

	while (*b != NULL)
	{
		m = find_max_index(*b);
		p = pos_index(*b, m);
		if (p == -1)
			break ;
		len = stack_len(*b);
		if (p <= len / 2)
		{
			while (p-- > 0)
				rb(b);
		}
		else
		{
			steps = len - p;
			while (steps-- > 0)
				rrb(b);
		}
		pa(a, b);
	}
}

void	k_sort(t_node **a, t_node **b)
{
	int	n;
	int	width;
	int	soft_pct;

	if (a == NULL || *a == NULL)
		return ;
	n = stack_len(*a);
	if (n <= 5 || is_sorted(*a))
		return ;
	if (n <= 100)
		width = n / 5;
	else
		width = n / 11;
	if (width < 1)
		width = 1;
	soft_pct = 133;
	phase_one(a, b, width, soft_pct);
	phase_two(a, b);
}
