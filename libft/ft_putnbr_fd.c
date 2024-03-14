/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 08:33:11 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/07 15:39:58 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	num;

	if (n == -2147483648)
	{
		write (fd, "-2147483648", 11);
		return ;
	}
	else
	{
		if (n < 0)
		{
			write (fd, "-", 1);
			n = n * -1;
		}
		if (n >= 10)
			ft_putnbr_fd(n / 10, fd);
		num = ((n % 10) + '0');
		write (fd, &num, 1);
	}
}
/*int main(void)
{

    ft_putnbr_fd(2147483648LL, 2);
    return 1;
}*/
