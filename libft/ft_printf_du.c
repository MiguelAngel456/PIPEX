/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_du.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:19:13 by mfuente-          #+#    #+#             */
/*   Updated: 2024/01/04 11:17:34 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//NUMERO ENTERO NORMAL CON SIGNO
int	ft_printf_d(int num)
{
	char	*number;
	int		i;
	int		lengt;

	number = ft_itoa(num);
	lengt = ft_strlen(number);
	i = 0;
	while (number[i] != '\0')
	{
		write(1, &number[i], 1);
		i++;
	}
	free(number);
	return (lengt);
}

//NUMERO ENTERO NORMAL SIN SIGNO
int	ft_printf_u(unsigned int num)
{
	char	number;
	int		i;

	i = 0;
	if (num > 9)
	{
		i = ft_printf_u(num / 10);
	}
	i++;
	number = num % 10 + '0';
	write(1, &number, 1);
	return (i);
}
