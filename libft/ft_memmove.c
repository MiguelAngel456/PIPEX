/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 19:37:42 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/04 18:56:08 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <memory.h>
//#include <string.h>
//#include <stdio.h>
//Copia el espacio de memoria
#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*d;
	const char	*s;

	d = dst;
	s = src;
	if (s == NULL && d == NULL)
		return (0);
	if (s < d)
	{
		d = d + len - 1;
		s = s + len - 1;
		while (len--)
		{
			*d-- = *s--;
		}
	}
	else if (s >= d)
	{
		while (len--)
		{
			*d++ = *s++;
		}
	}
	return (dst);
}
/*int main (void)
{
    // Caso 1: Bloques no superpuestos
    char source1[] = "Hello, World!";
    char destination1[20];

    printf("Caso 1 (Bloques no superpuestos):\n");
    printf("Antes de ft_memmove:\n");
    printf("Source: %s\n", source1);
    printf("Destination: %s\n", destination1);

    //ft_memmove(destination1, source1, 13);
    //memmove(destination1, source1, 13);


    printf("Source: %s\n", ft_memmove(((void *)0), ((void *)0), 5));
    printf("Destination: %s\n", memmove(((void *)0), ((void *)0), 5));

}*/