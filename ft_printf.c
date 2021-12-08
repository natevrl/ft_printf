/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:36:47 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/08 19:11:07 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

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

void	ft_putstr(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		ft_putchar(str[i]);
}
void	find_format(char c, va_list *arg_ptr)
{
	
	if (c == 'c')
		ft_putchar(va_arg(*arg_ptr, int));
	if (c == 's')
		ft_putstr(va_arg(*arg_ptr, char *));
	if (c == 'd')
		ft_putstr(ft_itoa(va_arg(*arg_ptr, char *)));
	if (c == 'i')
		ft_putchar(va_arg(*arg_ptr, int));
	if (c == 'u')
		ft_putchar((va_arg(*arg_ptr, int)));
	if (c == 'p')
		ft_putchar((va_arg(*arg_ptr, int)));
	if (c == 'x')
		ft_putchar((va_arg(*arg_ptr, int)));
	if (c == 'X')
		ft_putchar((va_arg(*arg_ptr, int)));
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

int main()
{
	ft_printf("test 1 : %d", 100);
	return(0);
}
