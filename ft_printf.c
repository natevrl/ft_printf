/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:36:47 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/08 22:28:42 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"
#include <unistd.h>

//cspdiuxX%
/*
c = va_arg(args, int)
s = va_arg(args, char *)
d = va_arg(args, int)
i = va_arg(args, int)
u = va_arg(args, unsigned int)
p = va_arg(args, unsigned long)# or 
                               #(unsigned long)va_arg(args, void *);
x = va_arg(args, unsigned int)
X = va_arg(args, unsigned int)
*/

// Une fonction qui initialise un les valeurs du tableau
// Dans printf = 
// 			On boucle sur la string[i]
// 			des que string[i] == %, cest qu'on a a faire a une variable
// 			Evaluer le format de la variable rencontrer
// Une fonction EVALUATE_FORMAT
	
int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
	return (i);
}

int	lenumber(int nbr)
{
	int	i;

	if (nbr == 0)
		return (1);
	i = 0;
	while (nbr)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int ft_putnbr(int nb)
{
	
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return (11);
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (lenumber(nb));
}

int	putnbr_unsigned(unsigned int nb)
{
	if (nb > 9)
	{
		putnbr_unsigned(nb / 10);
		putnbr_unsigned(nb % 10);
	}
	else
		ft_putchar(nb + 48);
	return (lenumber(nb));
}



int	hexa_putnbr(long int nb)
{
	char *base;

	base = "0123456789abcdef";
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 15)
	{
		hexa_putnbr(nb / 16);
		hexa_putnbr(nb % 16);
	}
	else
	{
		ft_putchar(base[nb]);
	}
	return (lenumber(nb));
}

int	hexa_putnbr_unsigned(unsigned long long int nb)
{
	char *base;
	
	base = "0123456789abcdef";
	if (nb > 15)
	{
		hexa_putnbr_unsigned(nb / 16);
		hexa_putnbr_unsigned(nb % 16);
	}
	else
		ft_putchar(base[nb]);
	return (14);
}

int find_format(char c, va_list *arg_ptr)
{
	if (c == 'c')
		return ft_putchar(va_arg(*arg_ptr, int));
	else if (c == 's')
		return ft_putstr(va_arg(*arg_ptr, char *));
	else if (c == 'i' || c == 'd')
		return ft_putnbr(va_arg(*arg_ptr, int));
	else if (c == 'u')
		return putnbr_unsigned((va_arg(*arg_ptr, int)));
	else if (c == 'p')
	{
		write(1, "0x", 2);
		return hexa_putnbr_unsigned(va_arg(*arg_ptr, unsigned long long int));
	}
	else if (c == 'x')
		return hexa_putnbr(va_arg(*arg_ptr, int));
	else if (c == 'X')
		return ft_putchar((va_arg(*arg_ptr, int)));
	else if (c == '%')
		return ft_putchar('%');
	else
		return (0);
}

int ft_printf(const char *str, ...)
{
	int i;
	int ret;
	va_list arg_ptr;
	
	ret = -2;
	i = 0;
	va_start(arg_ptr, str);
	while(str[i])
   {
	   if (str[i] == '%')
	   {
		   ret += find_format(str[i + 1], &arg_ptr);
		   i++;
	   }
	   else
		   ft_putchar(str[i]);
	   i++;
   }
	va_end(arg_ptr);
	return (ret + i);		
}


#include <stdio.h>
int main()
{
	unsigned long long int i = -111111111;
	printf("%d\n", printf("1: %p >> ", &i));
	ft_printf("%d\n", ft_printf("2: %p >> ", &i));
	return(0);
}
