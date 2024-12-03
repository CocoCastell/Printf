/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 15:07:03 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/03 18:57:06 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>

typedef struct s_parse
{
	bool	plus;
	bool	diez;
	bool	space;
	char	specifier;
	int		sign;
}				t_parse;

int	ft_printf(const char *format, ...);

#endif
