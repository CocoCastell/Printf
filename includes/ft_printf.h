/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/05 15:49:48 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdio.h>
# include "libft.h"

int	print_int(long nb, int base, int flag);
int	print_char(int c);
int	print_decimal(double d);
int	printf_string(char *str);
int	print_pointer(uintptr_t int_ptr);
int	ft_printf(const char *format, ...);
int	print_unsigned_int(unsigned int nb, int len);

#endif
