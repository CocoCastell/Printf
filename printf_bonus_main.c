/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_bonus_main.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cochatel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 16:37:25 by cochatel          #+#    #+#             */
/*   Updated: 2024/12/05 18:59:54 by cochatel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/ft_printf_bonus.h"

int	main(void)
{
	int	nb = 341;
	int printf_return = 0;

	ft_printf("#### Test amb 'd' ####\n");
	ft_printf("Test sense flag: |%d|\n", nb);
	ft_printf("Test amb '+': |%+d|\n", nb);
	ft_printf("Test amb ' ' : |% d|\n", nb);
	ft_printf("Test ERROR '#': |%#d|\n", nb);
	ft_printf("Test ERROR amb dos '#': |%##d|\n", nb);
	ft_printf("Test ERROR '#' i '+': |%#d|\n", nb);
	ft_printf("Test ERROR '#' i ' ': |%#+d|\n", nb);
	ft_printf("Test ERROR amb '+' i ' ' : |%+ d|\n", nb);
	ft_printf("Test ERROR amb ' ' i '+' : |%+ d|\n\n", nb);
	
	ft_printf("\n#### Test amb 'i' ####\n");
	ft_printf("Test sense flag: |%i|\n", nb);
	ft_printf("Test amb '+': |%+i|\n", nb);
	ft_printf("Test amb ' ' : |% i|\n", nb);
	ft_printf("Test ERROR '#': |%#i|\n", nb);
	ft_printf("Test ERROR amb dos '+': |%##i|\n", nb);
	ft_printf("Test ERROR '#' i '+': |%#i|\n", nb);
	ft_printf("Test ERROR '#' i ' ': |%#+i|\n", nb);
	ft_printf("Test ERROR amb '+' i ' ' : |%+ i|\n", nb);
	ft_printf("Test ERROR amb ' ' i '+' : |%+ i|\n\n", nb);
	
	ft_printf("\n####Test amb 'X' i 'x'####\n");
	ft_printf("Print return is: |%d|\n", printf_return);
	ft_printf("Test sense flag 'x': |%x|\n", nb);
	ft_printf("Test sense flag 'X': |%X|\n", nb);
	ft_printf("Test amb '#' i 'x': |%#x|\n", nb);
	ft_printf("Test amb '#' i 'X': |%#X|\n", nb);
	ft_printf("Test amb dos variables: |% d %#x %+i|\n", nb, nb ,nb);
	ft_printf("Test ERROR amb '+' i 'x': |%+x|\n", nb);
	ft_printf("Test ERROR amb ' ' i 'X': |% X|\n", nb);
	return (0);
}
