/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/30 08:47:05 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/04 18:55:30 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdlib.h>
//#include <stdio.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*devo;

	devo = malloc(count * size);
	if (!devo)
		return (0);
	ft_memset(devo, 0, count * size);
	return ((void *) devo);
}
/*int main(void)
{
    // Solicitar memoria para 5 enteros
    
	char *arr = ft_calloc(4, 20);

	printf("%s", arr);
	char *arr2 = calloc(4, 20);

	printf("\n%s", arr2);

    // Liberar la memoria cuando ya no se necesita
    free(arr);
    return (1);
}*/