/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 17:19:02 by mfuente-          #+#    #+#             */
/*   Updated: 2023/11/30 17:04:50 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	int		i;
	char	*p;

	i = 0;
	p = s;
	while (n > 0)
	{
		p[i] = 0;
		n--;
		i++;
	}
}
/*int main(void)
{
	char str[10] = "haaaaaaaaa";
	bzero(str, 5);
	printf("%s\n", str);
	
	char str2[] = "hola que tal";
	ft_bzero(str2, 5);
	printf("%s", str2);
	return 1;
}*/
