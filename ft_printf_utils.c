#include "ft_printf.h"


int ft_putnbr(int nb)
{
	
	int len;

	len = lenumber(nb);
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
		len++;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (len);

}

int	putnbr_unsigned(unsigned int nb)
{
	int len;

	len = unsigned_lenumber(nb);
	if (nb > 9)
	{
		putnbr_unsigned(nb / 10);
		putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (len);
}
