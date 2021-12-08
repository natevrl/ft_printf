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
	
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb %= 10);
	}
	else
	{
		ft_putchar(nb + 48);
	}
}

void	ft_putnbr_unsigned(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb %= 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}

void	ft_putnbr_hexa(long int nb)
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
		ft_putnbr_hexa(nb / 16);
		ft_putnbr_hexa(nb %= 16);
	}
	else
	{
		ft_putchar(base[nb]);
	}
}

void	ft_putnbr_unsi(unsigned long long int nb)
{
	char *base;
	int i;

	i = 0;
	base = "0123456789abcdef";
	if (nb > 15)
	{
		ft_putnbr_hexa(nb / 16);
		ft_putnbr_hexa(nb % 16);
	}
	else
		ft_putchar(base[nb]);
}

void	find_format(char c, va_list *arg_ptr)
{
	if (c == 'c')
		ft_putchar(va_arg(*arg_ptr, int));
	if (c == 's')
		ft_putstr(va_arg(*arg_ptr, char *));
	if (c == 'd')
		ft_putnbr(va_arg(*arg_ptr, int));
	if (c == 'i')
		ft_putnbr(va_arg(*arg_ptr, int));
	if (c == 'u')
		ft_putnbr_unsigned((va_arg(*arg_ptr, int)));
	if (c == 'p')
	{
		write(1, "0x", 2);
		ft_putnbr_unsi(va_arg(*arg_ptr, unsigned long long int));
	}
	if (c == 'x')
		ft_putnbr_hexa(va_arg(*arg_ptr, unsigned long long int));
	if (c == 'X')
		ft_putchar((va_arg(*arg_ptr, int)));
	if (c == '%')
		ft_putchar('%');
}

int ft_printf(const char *str, ...)
{
	int i;
	int ret;
	va_list arg_ptr;
	
	ret = 0;
	i = 0;
	va_start(arg_ptr, str);
	while(str[i])
   {
	   if (str[i] == '%')
	   {
		   find_format(str[i + 1], &arg_ptr);;
		   i++;
	   }
	   else
		   ft_putchar(str[i]);
	   i++;
   }
	va_end(arg_ptr);
	return (ret);		
}
#include <stdio.h>
int main()
{
	double i = -17.03;
	printf("test 1 : %d\n", i);
	ft_printf("test 1 : %p\n", &i);
	return(0);
}
