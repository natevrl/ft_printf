/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:36:47 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/08 15:49:27 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft/libft.h"

//cspdiuxX%

void	ft_putchar(char c)
{
	write(1, &c, 1);
}
char evaluate_format(char c)
{
	if (c == 'c')
		return 		
}

int ft_printf(const char *str, ...)
{
	int i;
	int ret;
	va_list arg_ptr;
	
	ret = 0;
	va_start(arg_ptr, str);
	while(str[i])
   {
	   if (str[i] == '%')
	   {
			Evaluate_format(str[i + 1]);
			va_arg(arg_ptr, le type);
	   }
	   ft_putchar(str[i]);
	   i++;
   }
	va_end(arg_ptr);
	return (ret);		
}

// Une fonction qui initialise un les valeurs du tableau
// Dans printf = 
// 			On boucle sur la string[i]
// 			des que string[i] == %, cest qu'on a a faire a une variable
// 			Evaluer le format de la variable rencontrer
// Une fonction EVALUATE_FORMAT

	
