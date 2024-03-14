/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_punt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 11:35:03 by mfuente-          #+#    #+#             */
/*   Updated: 2024/01/04 11:17:25 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	help_normi(char *hex_digits, unsigned long int valor_puntero,
				char *stack, int len)
{
	int	cont;

	cont = 0;
	if (valor_puntero == 0)
		stack[cont++] = '0';
	else
	{
		while (valor_puntero != 0)
		{
			stack[cont++] = hex_digits[valor_puntero % 16];
			valor_puntero /= 16;
		}
	}
	stack[cont] = '\0';
	write (1, "0x", 2);
	while (cont-- > 0)
		write (1, &stack[cont], 1);
	len = ft_strlen(stack)+2;
	return (len);
}

int	ft_printf_punt(void *var)
{
	unsigned long int	valor_puntero;
	int					len;
	char				*hex_digits;
	char				*stack;

	len = 0;
	valor_puntero = (unsigned long int)var;
	if (var == NULL)
	{
		write (1, "0x0", 3);
		return (3);
	}
	stack = malloc (sizeof(char) * (sizeof(void *) * 2 + 1));
	hex_digits = "0123456789abcdef";
	if (stack == NULL)
		return (0);
	len = help_normi(hex_digits, valor_puntero, stack, len);
	free(stack);
	return (len);
}
