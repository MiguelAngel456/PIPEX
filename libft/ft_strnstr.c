/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 15:18:20 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/04 13:36:03 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <string.h>
//#include <stdio.h>
#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	cont;
	size_t	cont_need;

	cont = 0;
	cont_need = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[cont] != '\0' && len > cont)
	{
		cont_need = 0;
		if (haystack[cont] == needle[0])
		{
			while (needle[cont_need] != '\0'
				&& haystack[cont + cont_need] == needle[cont_need]
				&& cont + cont_need < len)
			{
				if (needle[cont_need + 1] == '\0')
					return ((char *)&haystack[cont]);
				cont_need++;
			}
		}
		cont++;
	}
	return (NULL);
}
/*int main(void)
{
    // Caso 1: Subcadena encontrada al principio
    const char haystack1[30] = "abc";
    const char needle1[10] = "abc ";

    printf("PACO:\n");

    char* result1 = ft_strnstr(haystack1, "abcd", 9);
	char* result2 = strnstr(haystack1, "abcd", 9);
    printf("Resultado Mia: %p\n", result1);
	printf("Resultado Mia: %s\n", result1);
	printf("Resultado Original: %p\n", result2);
	printf("Resultado Original: %s\n", result2);

	return 1;
}*/