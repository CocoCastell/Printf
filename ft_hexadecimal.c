/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexadecimal.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/10 18:28:43 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_pointer(uintptr_t int_ptr)
{
	char	*base_chars;
	char	str[17];
	int		count;
	int		i;

	count = 0;
	base_chars = "0123456789abcdef";
	i = 0;
	while (int_ptr != 0)
	{
		str[i] = base_chars[int_ptr % 16];
		int_ptr /= 16;
		i++;
	}
	str[i] = '\0';
	while (--i >= 0)
		count += write(1, &str[i], 1);
	return (count);
}

int	print_hexadec(unsigned int nb, int flag)
{
	int		count;
	int		i;
	char	*base_chars;
	char	str[9];

	count = 0;
	if (flag == 0)
		base_chars = "0123456789abcdef";
	else if (flag == 1)
		base_chars = "0123456789ABCDEF";
	if (nb == 0)
		count = write(1, "0", 1);
	i = 0;
	while (nb != 0)
	{
		str[i] = base_chars[nb % 16];
		nb /= 16;
		i++;
	}
	str[i] = '\0';
	while (--i >= 0)
		count += write(1, &str[i], 1);
	return (count);
}
