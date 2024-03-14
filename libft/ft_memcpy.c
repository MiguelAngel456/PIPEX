/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 18:22:03 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/03 11:02:27 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	int			i;
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	i = 0;
	if (n == 0 || (dst == src))
		return (dst);
	while (0 < n)
	{
		d[i] = s[i];
		i++;
		n--;
	}
	return (dst);
}
/*int main(void)
{
	char str3[] = "pata";
	char str4[] = "xqq";
	//memcpy(str4, str3, 4);
	printf("%p\n", memcpy(str4, str3, 4));
	printf("%p", ft_memcpy(str4, str3, 4));


	char dest[100];
	ft_memset(dest, 'A', 100);
	ft_memcpy(dest, "coucou", 0);
	char *rtn = (char *)ft_memcpy(dest, NULL, 0);
	printf("%p\n", rtn);
	printf("%p\n", dest);
	printf("%c\n", dest[0]);
	return 1;
}*/
