/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 18:47:24 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/01 18:16:39 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int	cont;

	cont = 0;
	while ((s1[cont] != '\0' || s2[cont] != '\0') && 0 < n)
	{
		if (s1[cont] != s2[cont])
			return ((unsigned char)s1[cont] - (unsigned char)s2[cont]);
		cont++;
		n--;
	}
	return (0);
}

/*int main(void)
{
    char str1[] = "abcdef";
	char str2[13] = "abc\375xx";
	printf("%d\n", strncmp(str1, str2, 5));
	printf("%d", ft_strncmp(str1, str2, 5));
}*/