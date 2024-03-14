/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 10:43:03 by mfuente-          #+#    #+#             */
/*   Updated: 2024/01/04 11:20:50 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	aux(int lengt, va_list args, char letra)
{
	if (letra == 'c')
		lengt = lengt + ft_printfchar(va_arg(args, int));
	else if (letra == 's')
		lengt = lengt + ft_printf_s(va_arg(args, char *));
	else if (letra == 'd')
		lengt = lengt + ft_printf_d(va_arg(args, int));
	else if (letra == 'i')
		lengt = lengt + ft_printf_d(va_arg(args, int));
	else if (letra == 'u')
		lengt = lengt + ft_printf_u(va_arg(args, unsigned int));
	else if (letra == 'x')
		lengt = lengt + ft_printf_x(va_arg(args, unsigned int));
	else if (letra == 'X')
		lengt = lengt + ft_printf_xm(va_arg(args, unsigned int));
	else if (letra == '%')
		lengt = lengt + ft_printf_por();
	else if (letra == 'p')
		lengt = lengt + ft_printf_punt(va_arg(args, void *));
	return (lengt);
}

int	ft_printf(char const *word, ...)
{
	int		i;
	int		lengt;
	va_list	args;

	va_start(args, word);
	if (write(1, "", 0) == -1)
		return (-1);
	i = 0;
	lengt = 0;
	while (word[i] != '\0')
	{
		if (word[i] == '%')
		{
			lengt = aux(lengt, args, word[i + 1]);
			i ++;
		}
		else
		{
			lengt++;
			write(1, &word[i], 1);
		}
		i++;
	}
	va_end(args);
	return (lengt);
}

/*int main(void)
{
	printf("%d\n", ft_printf("%p", ""));
	printf("%d\n\n", printf("%p", ""));

	printf("%d\n", ft_printf(" %x ", 0));
	printf("%d\n", printf(" %x ", 0));

	return 1;
}*/