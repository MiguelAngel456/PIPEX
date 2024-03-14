/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 17:35:41 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/07 09:34:04 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*final;
	int		i;

	if (!s || !f)
	{
		return (0);
	}
	final = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!final)
	{
		return (0);
	}
	i = 0;
	while (s[i] != '\0')
	{
		final[i] = f(i, s[i]);
		i++;
	}
	final[i] = '\0';
	return (final);
}

/*int main() {
    const char *cadena = "Hola, mundo!";

    // Llamada a la función ft_strmapi con la función to_uppercase
    char *resultado = ft_strmapi("", {(i, c) => i + c});

    // Imprimir el resultado
    printf("Cadena original: %s\n", cadena);
    printf("Cadena convertida a mayúsculas: %s\n", resultado);

    // Liberar la memoria asignada dinámicamente
    free(resultado);

    return 0;
}*/