#include "printflibft.h"

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

unsigned int	print_unsigned_int(unsigned int nb)
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
}
