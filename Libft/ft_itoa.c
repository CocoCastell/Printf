/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 15:04:59 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/08 19:10:42 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size(int n)
{
	size_t	i;

	i = 0;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i + 1);
}

static void	string(char *str, int n, int i)
{
	if (n == 0)
	{
		str[i] = 0 + '0';
		i++;
	}
	while (n > 0)
	{
		str[i] = n % 10 + '0';
		n /= 10;
		i++;
	}
	str[i] = '\0';
}

static void	inverse(char *str)
{
	char	c;
	size_t	len;
	size_t	i;
	size_t	k;
	size_t	j;

	len = ft_strlen(str);
	i = 0;
	j = 0;
	k = len / 2;
	if (str[i] == '-')
	{
		i++;
		k = (len / 2) + 1;
	}
	while (i < k)
	{
		c = str[len - 1 - j];
		str[len - 1 - j] = str[i];
		str[i] = c;
		i++;
		j++;
	}
	str[len] = '\0';
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;

	len = size(n);
	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	if (n < 0)
	{
		str[0] = '-';
		if (n == -2147483648)
		{
			str[1] = '8';
			string(str, 214748364, 2);
		}
		else
			string(str, -n, 1);
	}
	else
		string(str, n, 0);
	inverse(str);
	return (str);
}

/*#include <stdio.h>
int main()
{
	char *d = ft_itoa(8.6);
	printf("%s", d);
	free(d);
}*/
