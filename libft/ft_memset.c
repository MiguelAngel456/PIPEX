/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 15:48:30 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/05 12:12:09 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <string.h>
// #include <stdio.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)b;
	while (len-- > 0)
		*str++ = c;
	return (b);
}

/*int main (void)
{
	char str[20] = "";
	printf("%p\n",ft_memset(str, '\n', 6));
	printf("%s",ft_memset(str, '\n', 6));
	//char str2[] = "hola";
	printf("\n\n%p", memset(str,'\n', 6));
	printf("\n%s\n", memset(str,'\n', 6));
	return 1;
}*/