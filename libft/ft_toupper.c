/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:57:11 by mfuente-          #+#    #+#             */
/*   Updated: 2023/11/30 17:06:48 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <ctype.h>
//#include <stdio.h>
#include "libft.h"

int	ft_toupper(int c)
{
	if ((c >= 'a' && c <= 'z'))
	{
		c = c - 32;
	}
	return (c);
}
/*int main(void)
{
	printf("%c", toupper('7'));
	printf("\n%c", ft_toupper('7'));
	return 1;
}*/