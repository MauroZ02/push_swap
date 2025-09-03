/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/08 20:10:41 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/03 20:20:25 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (str[i])
	{
		print_char((int)str[i]);
		i++;
	}
	return (i);
}

int	print_format(char specifier, va_list args)
{
	int	i;

	i = 0;
	if (specifier == 'c')
		i += print_char(va_arg(args, int));
	else if (specifier == 's')
		i += print_str(va_arg(args, char *));
	else if (specifier == 'd' || specifier == 'i')
		i += print_dec(va_arg(args, int));
	else if (specifier == 'x' || specifier == 'X')
	{
		if (specifier == 'x')
			i += print_hex(va_arg(args, unsigned int), HEX_LOW_BASE);
		else
			i += print_hex(va_arg(args, unsigned int), HEX_UPP_BASE);
	}
	else if (specifier == 'u')
		i += print_unsigned(va_arg(args, unsigned int));
	else if (specifier == 'p')
		i += print_ptr(va_arg(args, unsigned long), HEX_LOW_BASE);
	else
		i += write(1, &specifier, 1);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;

	va_start(args, format);
	i = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				i += write(1, "%", 1);
			else
				i += print_format(*format, args);
		}
		else
			i += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (i);
}
