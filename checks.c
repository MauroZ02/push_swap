/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:23:30 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/03 21:28:27 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(int argc)
{
	if (argc != 5)
	{
		ft_putendl_fd("Error in arguments\n", 2);
		return (1);
	}
	else
		return (0);
}