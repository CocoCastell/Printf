/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:03 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/05 16:36:53 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_parse
{
	bool	plus;
	bool	diez;
	bool	space;
	char	specifier;
	int		width;
	int		sign;
}				t_parse;

int	ft_printf(const char *format, ...);
int	print_unsigned_int(unsigned int nb, int len);
int	print_pointer(uintptr_t int_ptr);
int	print_int(long nb, int base, int flag);
int	printf_string(char *str);
int	type_manager(t_parse *parsing, char conversion, va_list ap);

#endif
