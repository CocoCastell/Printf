#include <stdio.h>
#include "includes/ft_printf.h"

int main()
{
	char *null_str = NULL;
	int	nb = -1;
	int n = ft_printf("% s", null_str); 
	printf("\n%d\n", n);
	return (0);
}
