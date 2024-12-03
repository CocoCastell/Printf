/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:34:25 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/03 18:56:37 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	diez(t_parse *parsing)
{
	if (parsing->specifier == 'x')
		return (write(1, "0x", 2));
	if (parsing->specifier == 'X')
		return (write(1, "0X", 2));
	else
		return (0);
}

void	print_flags(t_parse *parsing)
{
	int	count;

	if (parsing->specifier == 'd' || parsing->specifier == 'i')
		check_sign();
	if (parsing->diez == true)
		count += diez(parsing);
	//if (parsing->space == true)
}

void	int_manager(t_parse *parsing, long nb)
{
	int count;

	count = 0;
	if (parse->diez == true)
	{
		if (nb >= 0)
			count = write(1, '+', 1);
	}
	if (parse->space == true && )

}

static int	type_manager(t_parse *parsing, char conversion, va_list ap)
{
	int	count;

	count = 0;
	if (conversion == 'c' || conversion == '%')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		count++;
	}
	else if (conversion == 's')
		count = printf_string(va_arg(ap, char *));
	else if (conversion == 'i' || conversion == 'd')
	{
		count =
		count = print_int((long)va_arg(ap, int), 10, 0);
	}
	else if (conversion == 'p')
		count = print_pointer(va_arg(ap, uintptr_t));
	else if (conversion == 'u')
		count = print_unsigned_int(va_arg(ap, unsigned int));
	else if (conversion == 'x')
		count = print_int((long)va_arg(ap, unsigned int), 16, 0);
	else if (conversion == 'X')
		count = print_int((long)va_arg(ap, unsigned int), 16, 1);
	return (count);
}
