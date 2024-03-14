/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:45:30 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/01 16:13:31 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;
	char	*s2;

	s2 = (char *)s;
	i = 0;
	while (s[i] != (unsigned char)c)
	{
		if (s[i] == '\0')
		{
			return (NULL);
		}
		i++;
	}
	return (&s2[i]);
}
/*int main(void)
{
	printf("%p", strchr("teste", '\0'));
	printf("\n%p", ft_strchr("teste", '\0'));
	return 1;	
}*/