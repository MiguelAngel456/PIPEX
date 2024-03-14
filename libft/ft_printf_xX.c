/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:58:18 by mfuente-          #+#    #+#             */
/*   Updated: 2024/01/04 11:17:17 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//EN MINUSCULAS
int	ft_printf_x(unsigned int hex)
{
	int		digit;
	char	num;
	int		lengt;

	lengt = 0;
	if (hex >= 16)
		lengt = lengt + ft_printf_x(hex / 16);
	digit = hex % 16;
	if (digit == 0)
	{
		write(1, "0", 1);
		return (lengt + 1);
	}
	if (digit < 10)
		num = digit + '0';
	else
		num = (digit - 10) + 'a';
	write(1, &num, 1);
	lengt++;
	return (lengt);
}

//EN MAYUSCULAS
int	ft_printf_xm(unsigned int hex)
{
	int		digit;
	char	num;
	int		lengt;

	lengt = 0;
	if (hex >= 16)
		lengt = lengt + ft_printf_xm(hex / 16);
	digit = hex % 16;
	if (digit == 0)
	{
		write(1, "0", 1);
		return (lengt + 1);
	}
	if (digit < 10)
		num = digit + '0';
	else
		num = (digit - 10) + 'A';
	write(1, &num, 1);
	lengt++;
	return (lengt);
}
