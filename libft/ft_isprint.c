/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 15:24:44 by mfuente-          #+#    #+#             */
/*   Updated: 2023/11/30 17:05:21 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
//#include <ctype.h>
#include "libft.h"

int	ft_isprint(int digit)
{
	if (digit == ' ')
		return (1);
	else
		if (digit >= 32 && digit <= 126)
			return (1);
	return (0);
}
/*int main (void)
{
	printf("%d", ft_isprint('	'));
   	printf("%d", isprint('	'));
	return 1;	
}*/
