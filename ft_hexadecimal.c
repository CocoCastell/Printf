#include <stdint.h>

int	print_pointer(uintptr_t ptr)
{
	char	*base_chars;

	base_chars = "0123456789abcdef";
}

int	print_hexadec(unsigned int nb, int cap)
{
	int		count;
	int		i;
	char	*base_chars;
	char	str[9];

	count = 0;
	if (cap == 0)
		base_chars = "0123456789abcdef";
	else if (cap == 1)
		base_chars = "0123456789ABCDEF";
	if (nb == 0)
		count = write(1, '0', 1);
	i = 0;
	while (nb != '0')
	{
		str[i] = base_chars[nb % 16];
		nb /= 16;
		i++;
	}
	str[i--] = '\0';
	while (i >= 0)
	{
		write(1, &str[i], 1);
		i--;
	}
	return (count);
}
