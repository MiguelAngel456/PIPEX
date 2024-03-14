/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 19:01:28 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/04 20:05:25 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
	{
	char	*substr;
	char	*substr2;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
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
/*int main(void){
    char *s = "HOLA MONOS CON NAVAJA";
    char *s2;
    s2 = ft_substr(s, 5, 5);
    printf("%s", s2);
}*/