/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:23:08 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/01 18:50:17 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	cont_dst;
	size_t	letras_faltantes;
	size_t	cont;
	size_t	tamano_total;

	cont_dst = 0;
	cont = 0;
	letras_faltantes = 0;
	while (dst[cont_dst] != '\0')
		cont_dst++;
	letras_faltantes = (dstsize - cont_dst) - 1;
	if (dstsize <= ft_strlen(dst))
		return (ft_strlen(src) + dstsize);
	else
	{
		tamano_total = ft_strlen(src) + ft_strlen(dst);
		while (cont < letras_faltantes && src[cont] != '\0')
		{
			dst[cont_dst] = src[cont];
			cont++;
			cont_dst++;
		}
	}
	dst[cont_dst] = '\0';
	return (tamano_total);
}
/*int main(void)
{
	char str1[20] = "pqrstuvwxyz";
	char str2[] = "abcd";
	char str3[20] = "pqrstuvwxyz";
	char str4[] = "abcd";
	printf("%zu\n", strlcat(str1, str2, 7));
	printf("%s\n", str1);
	printf("%zu\n", ft_strlcat(str3, str4, 7));
	printf("%s\n", str3);
	
	return 1;
}*/