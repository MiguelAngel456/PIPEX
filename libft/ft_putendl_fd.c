/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 19:47:26 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/07 08:32:51 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
	{
	int	cont;

	cont = 0;
	if (s == NULL)
		return ;
	while (s[cont] != '\0')
	{
		write (fd, &s[cont], 1);
		cont++;
	}
	write (fd, "\n", 1);
}
