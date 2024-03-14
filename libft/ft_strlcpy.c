/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 08:32:18 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/01 17:10:41 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (src[j] != '\0')
		j++;
	if (dstsize == 0)
		return (j);
	while (src[i] != '\0' && i < dstsize -1)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (j);
}
/*int main(void)
{
	char destination[10];
    const char *source = "Hello, World!";

    size_t copied = ft_strlcpy(destination, source, sizeof(destination));
	size_t copied2 = strlcpy(destination, source, sizeof(destination));

    printf("My: %zu\n", copied);
    printf("Origin: %zu\n", copied2);

	return (0);
}*/