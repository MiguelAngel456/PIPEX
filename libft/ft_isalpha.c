/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:34:28 by mfuente-          #+#    #+#             */
/*   Updated: 2023/11/30 17:05:06 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isalpha(int letra)
{
	if ((letra >= 'a' && letra <= 'z')
		|| (letra >= 'A' && letra <= 'Z'))
	{
		return (1);
	}
	return (0);
}

/*int main(void){
	printf("%d",isalpha('A'));
	printf("%d",ft_isalpha('*'));
	return 0;
}*/
