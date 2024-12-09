/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:59:15 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/05 18:59:28 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

static void	init_struct(t_parse *parsing)
{
	parsing->diez = false;
	parsing->space = false;
	parsing->plus = false;
	parsing->specifier = 'q';
	parsing->width = 1;
	parsing->sign = 0;
}

static int	check_error(const char *format, int occurence[3])
{
	if (occurence[0] > 1)
		write(2, "warning: repeated '#' flag in format\n", 37);
	if (occurence[1] > 1)
		write(2, "warning: repeated ' ' flag in format\n", 37);
	if (occurence[2] > 1)
		write(2, "warning: repeated '+' flag in format\n", 37);
	if (occurence[1] > 0 && occurence[2] > 0)
		write(2, "warning: ' ' flag ignored\n", 26);
	if (*format == '\0')
		return (-1);
	if (occurence[0] == 1 && (*format != 'x' && *format != 'X'))
		return (-1);
	if (occurence[1] == 1 && (*format != 'd' && *format != 'i'))
		write(2, "warning: ' ' flag used with wrong flag\n", 39);
	if (occurence[2] == 1 && (*format != 'd' && *format != 'i'))
		return (-1);
	return (0);
}

static void	fill_struct(const char *format, int occurence[3], t_parse *parsing)
{
	if (occurence[0] > 0)
	{
		parsing->diez = true;
		parsing->width += occurence[0];
	}
	if (occurence[1] > 0)
	{
		parsing->space = true;
		parsing->width += occurence[1];
	}
	if (occurence[2] > 0)
	{
		parsing->plus = true;
		parsing->width += occurence[2];
	}
	parsing->specifier = *format;
}

static int	struct_manager(const char *format, t_parse *parsing)
{
	int		occurence[3];

	occurence[0] = 0;
	occurence[1] = 0;
	occurence[2] = 0;
	while (*format || (*format != 'c' && *format != 's' && *format != 'p' && \
	*format != 'd' && *format != 'i' && *format != 'u' && *format != 'x' && \
	*format != 'X' && *format != '%'))
	{
		if (*format == '#')
			occurence[0]++;
		else if (*format == ' ')
			occurence[1]++;
		else if (*format == '+')
			occurence[2]++;
		else
			break ;
		format++;
	}
	if (check_error(format, occurence) == 0)
		return (fill_struct(format, occurence, parsing), 0);
	else
		return (write(1, "ERROR\n", 6));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_parse		*parsing;
	int			count;
	int			check_null;

	if (format == NULL)
		return (-1);
	parsing = malloc(sizeof(t_parse));
	if (parsing == NULL)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		init_struct(parsing);
		if (*format == '%')
		{
			if (struct_manager(++format, parsing) > 0)
				return (va_end(ap), free(parsing), -1);
			check_null = type_manager(parsing, *(format - 1 + parsing->width), ap);
			if (check_null == -1)
				check_null = write(1, "(null)", 6);
			count += check_null;
		}
		else
			count += write(1, format, 1);
		format += parsing->width;
	}
	return (va_end(ap), free(parsing), count);
}
