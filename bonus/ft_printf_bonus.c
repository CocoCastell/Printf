/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:59:15 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/05 15:12:38 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"
#include <stdio.h>

static int	init_struct(t_parse *parsing)
{
	parsing->diez = false;
	parsing->space = false;
	parsing->plus = false;
	parsing->specifier = 'q';
	parsing->width = 0;
	parsing->sign = 0;
	return (0);
}

static int	check_error(const char *format, int occurence[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (occurence[i] > 1)
			return (-1);
		i++;
	}
	if (*format != 'c' && *format != 's' && *format != 'p' && *format != 'd' \
	&& *format != 'i' && *format != 'u' && *format != 'x' && *format != 'X'\
	&& *format != '%')
		return (-1);
	if (occurence[1] == 1 && occurence[2] == 1)
		return (-1);
	if (occurence[0] == 1 && (*format != 'x' && *format != 'X'))
		return (-1);
	if (occurence[1] == 1 && (*format != 'd' && *format != 'i'))
		return (-1);
	if (occurence[2] == 1 && (*format != 'd' && *format != 'i'))
		return (-1);
	return (0);
}

static void	fill_struct(const char *format, int occurence[3], t_parse *parsing)
{
	if (occurence[0] == 1)
	{
		parsing->diez = true;
		parsing->width++;
	}
	if (occurence[1] == 1)
	{
		parsing->space = true;
		parsing->width++;
	}
	if (occurence[2] == 1)
	{
		parsing->plus = true;
		parsing->width++;
	}
	parsing->specifier = *format;
}

static int	struct_manager(const char *format, t_parse *parsing)
{
	int		occurence[3];

	occurence[0] = 0;
	occurence[1] = 0;
	occurence[2] = 0;
	while (*format)
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
	{
		fill_struct(format, occurence, parsing);
		return (0);
	}
	else
		return (write(1, "ERROR\n", 6));
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_parse		*parsing;
	int			count;

	if (format == NULL)
		return (-1);
	parsing = malloc(sizeof(t_parse));
	if (parsing == NULL)
		return (-1);
	count = 0;
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			init_struct(parsing);
			if (struct_manager(++format, parsing) > 0)
				return (-1);
			count += type_manager(parsing, format[parsing->width], ap);
			format += parsing->width;
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
