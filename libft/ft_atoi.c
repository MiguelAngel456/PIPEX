/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 18:39:44 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/04 18:40:03 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
static int	ignorar_espacios(int cont, char *str)
{
	while (str[cont] == '\t' || str[cont] == '\n'
		|| str[cont] == '\v' || str[cont] == '\f'
		|| str[cont] == '\r' || str[cont] == ' ')
		cont++;
	return (cont);
}

int	ft_atoi(const char *str)
{
	int		cont;
	int		num_final;
	char	*original;
	char	signo;

	cont = 0;
	num_final = 0;
	original = (char *)str;
	cont = ignorar_espacios(cont, original);
	signo = str[cont];
	if ((signo != '+' && signo != '-') && (signo < '0' && signo > '9'))
		return (0);
	if ((signo == '+' || signo == '-'))
		cont++;
	while (str[cont] != '\0' && (str[cont] >= '0' && str[cont] <= '9'))
	{
		num_final = num_final * 10 + (str[cont] - '0');
		cont++;
	}
	if (signo == '-')
		num_final = num_final * -1;
	return (num_final);
}
/*int main(void)
{
    // Caso 1: Número positivo
   const char str1[] = "+12345";

    printf("Caso 1 (Número positivo):\n");
    printf("Cadena: %s\n", str1);

    int result1 = ft_atoi(str1);

    printf("Resultado: %d\n", result1);

    // Caso 2: Número negativo
    const char str2[] = " +  -+6789";

    printf("\nCaso 2 (Número negativo):\n");
    printf("Cadena: %s\n", str2);

    int result2 = ft_atoi(str2);
	int result3 = atoi(str2);
    printf("Resultado: %d\n%d", result2, result3);
}*/