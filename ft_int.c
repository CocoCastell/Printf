/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <cochatel@student.42barcelona.com>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/10 14:47:37 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/10 15:51:45 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	print_int(int nb)
{
	int		count;
	char	*str;

	str = ft_itoa(nb);
	count = 0;
	while (str[count] != '\0')
	{
		write(1, &str[count], 1);
		count++;
	}
	return (count);
}

static int	nb_length(unsigned int nb)
{
	int	count;

	count = 0;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count + 1);
}

static char	*unsigned_str(unsigned int nb, int len)
{
	char	*str;
	int		i;
	int		j;

	str = malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = 0;
	j = len - 1;
	while (j >= 0)
	{
		str[j] = nb % 10 + '0';
		j--;
		nb /= 10;
	}
	str[len] = '\0';
	return (str);
}

int	print_unsigned_int(unsigned int nb)
{
	int		count;
	int		i;
	int		len;
	char	*str;

	count = 0;
	len = nb_length(nb);
	str = unsigned_str(nb, len);
	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (count);
}
