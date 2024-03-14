/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 11:08:24 by mfuente-          #+#    #+#             */
/*   Updated: 2024/01/04 11:17:21 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_s(char *word)
{
	int				i;
	unsigned char	letter;

	i = 0;
	if (word == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	else
	{
		while (word[i] != '\0')
		{
			letter = word[i];
			write(1, &letter, 1);
			i++;
		}
	}
	return (ft_strlen(word));
}
