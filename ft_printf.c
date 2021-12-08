/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenhado <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 14:36:47 by nbenhado          #+#    #+#             */
/*   Updated: 2021/12/07 14:39:12 by nbenhado         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>


int ft_printf(const char *, ...)
{
   va_list va;
   va_start(va, s);
			
}

// Une fonction qui initialise un les valeurs du tableau
// Dans printf = 
// 			On boucle sur la string[i]
// 			des que string[i] == %, cest qu'on a a faire a une variable
// 			Evaluer le format de la variable rencontrer
// Une fonction EVALUATE_FORMAT
