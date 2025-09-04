/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:59:51 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/04 20:30:20 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_node
{
	int				value;
	struct s_node	*next;
}	t_node;

/* movements.c */
t_node	*node_new(int value);
void	add_at_top(t_node **top, t_node *n);
t_node	*remove_at_top(t_node **top);
void	pb(t_node **a, t_node **b);
#endif