/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:59:15 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/03 18:58:30 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	init_struct(t_parse *parsing)
{
	parsing->diez = false;
	parsing->space = false;
	parsing->plus = false;
	parsing->specifier = 'q';
	parsing->sign = 0;
	return (0);
}

int	check_error(const char *format, int occurence[3])
{
	int	i;

	i = 0;
	while (i < 3)
	{
		if (occurence[i] > 1)
			return (1);
		i++;
	}
	if (*format != 'c' && *format != 's' && *format != 'p' && *format != 'd' \
	&& *format != 'i' && *format != 'u' && *format != 'x' && *format != 'X'\
	&& *format != '%')
		return (1);
	return (0);
}

void	fill_struct(const char *format, int occurence[3], t_parse *parsing)
{
	if (occurence[0] == 1)
		parsing->diez = true;
	//else
	//	parsing->diez = false;
	if (occurence[1] == 1)
		parsing->space = true;
	//else
	//	parsing->diez = false;
	if (occurence[2] == 1)
		parsing->plus = true;
	//else
	//	parsing->diez = false;
	parsing->specifier = *format;
}

const char	*struct_manager(const char *format, t_parse *parsing)
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
		return (format);
	}
	else
		return (NULL);
}

void	print_struct(t_parse *parsing)
{
	printf("\n");
	if (parsing->diez == true)
		printf("# --> true\n");
	if (parsing->diez == false)
		printf("# --> false\n");
	if (parsing->space == true)
		printf("' ' --> true\n");
	if (parsing->space == false)
		printf("' ' --> false\n");
	if (parsing->plus == true)
		printf("+ --> true\n");
	if (parsing->plus == false)
		printf("+ --> false\n");
	printf("Specifier is: %c\n", parsing->specifier);
}

int	ft_printf(const char *format, ...)
{
	va_list		ap;
	t_parse		*parsing;
	int			count;

	if (format == NULL)
		return (0);
	count = 0;
	parsing = malloc(sizeof(t_parse));
	if (parsing == NULL)
		return (0);
	va_start(ap, format);
	while (*format)
	{
		if (*format == '%')
		{
			init_struct(parsing);
			if (struct_manager(++format, parsing) == NULL)
				break ;
			count += type_manager(*(++format), ap);
		}
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}
