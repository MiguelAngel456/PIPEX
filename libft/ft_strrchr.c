/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 17:47:48 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/01 16:16:00 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	while (s[i] != '\0')
	{
		i++;
	}
	while (i >= 0)
	{
		if (s[i] == (unsigned char)c)
		{
			return (&s2[i]);
		}
		i--;
	}
	return (0);
}
/*int main(void)
{
    // Caso 1: Carácter encontrado al final
    const char str1[] = "teste";
    int ch1 = 'e';

    printf("PRUEBAS PACO:\n");
    printf("Cadena: %s\n", str1);
    printf("Carácter a buscar: %c\n", ch1);

    char* result1 = ft_strrchr(str1, ch1);
    char* result11 = strrchr(str1, ch1);

    printf("Resultado: %p\n", result1);
    printf("Resultado: %s\n", result1);
    printf("%s\n", "****************************");
    printf("Resultado: %p\n", result11);
    printf("Resultado: %s\n", result11);

    return 0;
}*/