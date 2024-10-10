/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/10 18:28:54 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int	printf_string(char *str)
{
	int		count;

	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

int	print_char(int c)
{
	c = (char)c;
	write(1, &c, 1);
	return (1);
}

int	type_manager(char conversion, va_list ap)
{
	int	count;

	count = 0;
	if (conversion == 'c')
		count = print_char(va_arg(ap, int));
	else if (conversion == 's')
		count = printf_string(va_arg(ap, char *));
	else if (conversion == 'i')
		count = print_int(va_arg(ap, int));
	else if (conversion == 'd')
		count = print_int(va_arg(ap, int));
	else if (conversion == 'p')
		count = print_pointer(va_arg(ap, uintptr_t));
	else if (conversion == 'u')
		count = print_unsigned_int(va_arg(ap, unsigned int));
	else if (conversion == 'x')
		count = print_hexadec(va_arg(ap, unsigned int), 0);
	else if (conversion == 'X')
		count = print_hexadec(va_arg(ap, unsigned int), 1);
	else if (conversion == '%')
		count = write(1, "%", 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		count;

	if (format == NULL)
		return (0);
	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += type_manager(*(++format), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

int	main(void)
{
	int	count;
	int	a;

	a = 9;
	count = ft_printf("Bon di%c\n", 'a');
	printf("%d chars written\n", count);
	count = ft_printf("Bon %s\n", "dia");
	printf("%d chars written\n", count);
	count = ft_printf("Tens %i anys\n", 26);
	printf("%d chars written\n", count);
	count = ft_printf("Tens %x hexadecimal anys\n", 26);
	printf("%d chars written\n", count);
	count = ft_printf("Tens %X hexadecimal anys\n", 26);
	printf("%d chars written\n", count);
	count = ft_printf("Tens %d decimal anys\n", 26.56);
	printf("%d chars written\n", count);
	count = ft_printf("Punter: %p\n", &a);
	printf("Vrai printf: %p\n", &a);
	printf("%d chars written\n", count);
	count = ft_printf("Test percentatge:%%\n");
	printf("%d chars written\n", count);
	count = ft_printf(NULL);
	return (0);
}
