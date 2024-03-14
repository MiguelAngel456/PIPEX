/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 08:27:03 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/05 13:52:36 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_contain(char c, const char *set)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
		{
			return (1);
		}
		i++;
	}
	return (0);
}

static char	*ft_aux(int i, int cont, char const *s1, char *aux)
{
	int	j;

	j = 0;
	while (i <= cont)
	{
		aux[j] = s1[i];
		j++;
		i++;
	}
	aux[j] = '\0';
	return (aux);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*aux;
	int		i;
	int		cont;

	i = 0;
	if (!s1)
		return (NULL);
	cont = ft_strlen(s1) - 1;
	while (s1[i] != '\0' && 1 == ft_contain(s1[i], set))
		i++;
	while (cont >= 0 && 1 == ft_contain(s1[cont], set))
		cont--;
	if (i > cont)
	{
		aux = (char *)malloc(1);
		if (!aux)
			return (NULL);
		aux[0] = '\0';
		return (aux);
	}
	aux = (char *)malloc(((cont - i) + 2) * sizeof(char));
	if (!aux)
		return (0);
	aux = ft_aux(i, cont, s1, aux);
	return (aux);
}
/*int main(void)
{
	printf("%s", ft_strtrim("", ""));
	return 1;
}*/