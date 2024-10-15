/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 21:14:49 by cochatel          #+#    #+#             */
/*   Updated: 2024/10/08 18:46:24 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*str;
	size_t	tot_size;

	tot_size = nmemb * size;
	str = malloc(tot_size);
	if (str == NULL)
		return (NULL);
	ft_memset(str, 0, tot_size);
	return (str);
}
