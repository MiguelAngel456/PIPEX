/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 09:53:53 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/04 18:32:07 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int				cont;
	const unsigned char			*aux_s1;
	const unsigned char			*aux_s2;

	aux_s1 = (const unsigned char *) s1;
	aux_s2 = (const unsigned char *) s2;
	cont = 0;
	while (n > 0)
	{
		if (aux_s1[cont] != aux_s2[cont])
			return (aux_s1[cont] - aux_s2[cont]);
		cont++;
		n--;
	}
	return (0);
}
/*int main(void)
{
	printf("%d", memcmp("\xff\xaa\xde\xffMACOSX\xff", "\xff\xaa\xde\x02", 8));
	printf("%d", ft_memcmp("\xff\xaa\xde\xffMACOSX\xff", "\xff\xaa\xde\x02", 8));
	return 1;
}*/