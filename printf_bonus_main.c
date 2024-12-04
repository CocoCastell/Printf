#include "includes/ft_printf_bonus.h"

int	main(void)
{
	int	nb = 341;
	ft_printf("Test amb + : |%+d|\n", nb);
	ft_printf("Test amb espai : |% d|\n", nb);
	ft_printf("Test amb + i espai : |%+ d|\n", nb);
	ft_printf("Test amb espai i + : |%+ d|\n", nb);
	ft_printf("Test amb # i x: |%#X|\n", nb);
	ft_printf("Test amb # i d: |%#d|\n", nb);
	
	return (0);
}
