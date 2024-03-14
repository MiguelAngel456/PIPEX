/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:50:58 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/05 08:24:01 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*final;
	int		len;
	int		cont;
	int		lentotal;

	cont = 0;
	lentotal = ft_strlen(s1) + ft_strlen(s2) + 1;
	final = (char *)malloc(lentotal * sizeof(char));
	if (!final || !s1 || !s2)
		return (0);
	len = ft_strlen(s1);
	while (len--)
	{
		final[cont] = *s1++;
		cont++;
	}
	len = ft_strlen(s2);
	while (len--)
	{
		final[cont] = *s2++;
		cont++;
	}
	final[cont] = '\0';
	return (final);
}
/*int main(void)
{
	char *s1 = "hola ";
	char *s2 = "monos";

	char *s3 = ft_strjoin(s1,s2);
	printf("%s", s3);
	return 0;
}*/