/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 15:20:10 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/08 19:03:47 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	digitos(int n)
{
	int	aux;
	int	cont;

	aux = n;
	cont = 0;
	while (aux != 0)
	{
		cont++;
		aux /= 10;
	}
	return (cont);
}

static char	*negativos(int n, char *numero, int dig)
{
	int	i;

	i = 0;
	n = n * -1;
	if (!numero)
		return (0);
	i = digitos(n);
	numero[i + 1] = '\0';
	if (n == -2147483648)
	{
		numero[i] = '8';
		n /= 10;
		n = n * -1;
		i--;
	}
	numero[0] = '-';
	while (n > 0)
	{
		dig = n % 10;
		numero[i] = (dig + '0');
		i--;
		n /= 10;
	}
	return (numero);
}

static char	*positivos(int i, int dig, int n)
{
	char	*numero;

	numero = (char *)malloc(sizeof(char) * (digitos(n) + 1));
	if (!numero)
		return (0);
	i = digitos(n) - 1;
	numero[i + 1] = '\0';
	while (n > 0)
	{
		dig = n % 10;
		numero[i] = (dig + '0');
		i--;
		n /= 10;
	}
	return (numero);
}

char	*ft_itoa(int n)
{
	char	*numero;
	int		i;
	int		dig;

	dig = 0;
	if (n == 0)
	{
		numero = (char *)malloc(sizeof(char) * 2);
		if (!numero)
			return (0);
		numero[0] = '0';
		numero[1] = '\0';
	}
	else
	{
		i = 0;
		if (n > 0)
			numero = positivos(i, dig, n);
		else
		{
			numero = (char *)malloc(sizeof(char) * (digitos(n) + 2));
			numero = negativos (n, numero, dig);
		}
	}
	return (numero);
}

/*int main(void)
{
	int i = -1234;

	printf("%s\n",  ft_itoa(i));
	return 1;
}*/