/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 08:34:30 by mfuente-          #+#    #+#             */
/*   Updated: 2024/03/07 12:25:42 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

char	*ft_strchr_gnl(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (&((char *)s)[i]);
		i++;
	}
	if ((char)c == '\0')
		return (&((char *)s)[i]);
	return (0);
}

int	aux_gnl(char *final, char *s1, int cont)
{
	while (s1[cont])
	{
		final[cont] = s1[cont];
		cont++;
	}
	return (cont);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*final;
	int		len;
	int		cont;

	if (!s1)
	{
		s1 = malloc(sizeof(char) + 1);
		if (!s1)
			return (0);
		s1[0] = 0;
	}
	cont = 0;
	final = (char *)malloc(sizeof(char) * ft_strlen_gnl(s1)
			+ ft_strlen_gnl(s2) + 1);
	if (!final)
		return (ft_free(s1));
	cont = aux_gnl(final, s1, cont);
	len = 0;
	while (s2[len])
		final[cont++] = s2[len++];
	final[cont] = '\0';
	ft_free(s1);
	return (final);
}

char	*ft_substr_gnl(char *s, unsigned int start, size_t len)
	{
	char	*substr;
	char	*substr2;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen_gnl(s))
		return (NULL);
	if (len > ft_strlen_gnl(s + start))
		len = ft_strlen_gnl(s + start);
	substr = malloc((len + 1) * sizeof(char));
	if (substr == NULL)
		return (0);
	substr2 = substr;
	while (len--)
	{
		substr2[i] = s[start];
		start++;
		i++;
	}
	substr2[i] = '\0';
	return (substr);
}

size_t	ft_strlen_gnl(const char *str)
{
	int	cont;

	cont = 0;
	if (!str)
		return (0);
	while (str[cont])
		cont++;
	return (cont);
}
