/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/10 18:15:24 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdint.h>
# include "Libft/libft.h"

int	print_int(int nb);
int	print_char(int c);
int	print_decimal(double d);
int	printf_string(char *str);
int	print_pointer(uintptr_t int_ptr);
int	ft_printf(const char *format, ...);
int	print_unsigned_int(unsigned int nb);
int	print_hexadec(unsigned int nb, int flag);

#endif
