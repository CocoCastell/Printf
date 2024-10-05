#include "libftprintf.h"
#include <stdio.h>

int	print_arg(char c, va_list ap)
{
	int	count;
	
	count = 0;
	return (count);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int	count;

	va_start(ap, format);
	count = 0;
	while (*format)
	{
		if (*format == '%')
			count += print_arg(*(format++), ap);
		else
			count += write(1, format, 1);
		format++;
	}
	va_end(ap);
	return (count);
}

int main()
{
	int count;

	count = ft_printf("Hello %s, today is %d\n", "Coco", 16);
	printf("%d chars written\n", count);
	return (0);
}
