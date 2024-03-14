/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 09:46:59 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/05 09:59:19 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*nueva;
	char	*nuevo2;
	int		longitud;
	int		cont;

	cont = 0;
	longitud = ft_strlen(s1);
	nueva = malloc((longitud + 1) * sizeof(char));
	if (!nueva)
		return (NULL);
	nuevo2 = nueva;
	while (s1[cont] != '\0')
	{
		nuevo2[cont] = s1[cont];
		cont++;
	}
	nuevo2[cont] = '\0';
	return (nueva);
}

/*int main(void)
{
	    // Cadena de prueba
    const char *original = "";
    // Llamada a la función ft_strdup
    char *duplicado = ft_strdup(original);
	char *duplicado2 = strdup(original);
    printf("Mio:%p\n", duplicado);
	printf("Mio:%s\n", duplicado);
	printf("Original:%p\n", duplicado);
	printf("Original:%s\n", duplicado);
	//INTENTO DE COPIAR LO DE PACO
	
    free(duplicado);
	return 1;
}*/