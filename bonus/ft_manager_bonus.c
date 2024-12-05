/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:34:25 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/05 15:43:09 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

static int	check_diez(t_parse *parsing)
{
	if (parsing->diez == true)
	{
		if (parsing->specifier == 'x')
			return (write(1, "0x", 2));
		if (parsing->specifier == 'X')
			return (write(1, "0X", 2));
		return (0);
	}
	return (0);
}

static int	int_manager(t_parse *parsing, long nb)
{
	int	count;

	count = 0;
	if (parsing->plus == true && parsing->space == false && nb >= 0)
		count = write(1, "+", 1);
	if (parsing->space == true && parsing->plus == false && nb >= 0)
		count = write(1, " ", 1);
	count += print_int(nb, 10, 0);
	return (count);
}

int	type_manager(t_parse *parsing, char conversion, va_list ap)
{
	int	count;

	count = 0;
	count = check_diez(parsing);
	if (conversion == 'c' || conversion == '%')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		count++;
	}
	else if (conversion == 's')
		count += printf_string(va_arg(ap, char *));
	else if (conversion == 'i' || conversion == 'd')
		count += int_manager(parsing, (long)va_arg(ap, int));
	else if (conversion == 'p')
		count += print_pointer(va_arg(ap, uintptr_t));
	else if (conversion == 'u')
		count += print_unsigned_int(va_arg(ap, unsigned int), 0);
	else if (conversion == 'x')
		count += print_int((long)va_arg(ap, unsigned int), 16, 0);
	else if (conversion == 'X')
		count += print_int((long)va_arg(ap, unsigned int), 16, 1);
	return (count);
}
