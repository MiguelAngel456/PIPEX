/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 13:20:51 by mfuente-          #+#    #+#             */
/*   Updated: 2023/11/30 17:06:39 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>
#include "libft.h"

int	ft_tolower(int c)
{
	if ((c >= 'A' && c <= 'Z'))
	{
		c = c + 32;
	}
	return (c);
}
/*int main(void)
{
	printf("%c", tolower('A'));
	printf("\n%c", ft_tolower('A'));
	return 1;
}*/