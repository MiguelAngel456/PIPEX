/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 13:38:50 by mfuente-          #+#    #+#             */
/*   Updated: 2023/11/30 17:05:02 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include "libft.h"

int	ft_isalnum(int digit)
{
	if ((digit >= 'a' && digit <= 'z')
		|| (digit >= 'A' && digit <= 'Z'))
	{
		return (1);
	}
	if (digit >= '0' && digit <= '9')
		return (1);
	return (0);
}
/*int main(void)
{
	printf("%d", ft_isalnum('a'));
	printf("%d", ft_isalnum('7'));
	printf("%d", ft_isalnum('+'));
	return (0);
}*/
