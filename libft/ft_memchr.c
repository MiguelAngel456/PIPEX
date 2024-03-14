/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 08:52:53 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/02 12:29:01 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*texto_s;

	texto_s = (const unsigned char *)s;
	while (n > 0)
	{
		if (*texto_s == (unsigned char)c)
		{
			return ((void *)texto_s);
		}
		texto_s++;
		n--;
	}
	return (NULL);
}

/*int main(void)
{
    //printf("%p", memchr("Hola que tal", '\0', 6));
	//printf("\n%p", ft_memchr("Hola que tal", '\0', 6));
	//printf("\n%c", '\033');
	printf("\n%p", ft_memchr("\2333\233h", '\233', 34));
	printf("\n%p", memchr("\233\23233<K\233\233h", '\233', 34));

	return 1;
}*/