/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/05 16:06:10 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	type_manager(char conversion, va_list ap)
{
	int	count;

	count = 0;
	if (conversion == 'c')
	{
		ft_putchar_fd(va_arg(ap, int), 1);
		count++;
	}
	else if (conversion == 's')
		count = printf_string(va_arg(ap, char *));
	else if (conversion == 'i')
		count = print_int((long)va_arg(ap, int), 10, 2);
	else if (conversion == 'd')
		count = print_int((long)va_arg(ap, int), 10, 2);
	else if (conversion == 'p')
		count = print_pointer(va_arg(ap, uintptr_t));
	else if (conversion == 'u')
		count = print_unsigned_int(va_arg(ap, unsigned int), 0);
	else if (conversion == 'x')
		count = print_int((long)va_arg(ap, unsigned int), 16, 0);
	else if (conversion == 'X')
		count = print_int((long)va_arg(ap, unsigned int), 16, 1);
	else if (conversion == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;
	int		check_null;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			{
				check_null = type_manager(*(++format), ap);
				if (check_null == -1)
					check_null = write(1, "(null)", 6);
				count += check_null;
			}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
