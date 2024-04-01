/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_errors.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 10:48:38 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/01 15:11:09 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

//ERROR
int	ft_errors(void)
{
	write(2, "Error\n", ft_strlen("Error"));
	return (1);
}

//ALGUNOS CASOS DE ERROR
int	case_error(t_pipex *str_ppx)
{
	if (str_ppx->here_doc == NULL)
	{
		if (str_ppx->fd_i == -1 || str_ppx->fd_o == -1)
		{
			return (ft_errors());
		}
		if (!str_ppx->infile || !str_ppx->outfile)
			return (ft_errors());
	}
	else
	{
		if (str_ppx->fd_o == -1)
			return (ft_errors());
		if (!str_ppx->outfile)
			return (ft_errors());
	}
	return (0);
}

//COMPROBAR SI ES EL COMANDO AWK Y O EL SED
int	special_case(char *command, char *s)
{
	int	n;

	n = 3;
	if (!command || !s)
		return (1);
	while (*command && n--)
	{
		if (*(command++) != *(s++))
			return (1);
	}
	if (*(command++) != *(s++))
		return (1);
	return (0);
}

//COMPROBAR QUE EL SACO ESPECIAL ESTA BIEN
int	ft_chrcnt(char *str, char c)
{
	int	i;
	int	com;

	i = -1;
	com = 0;
	if (str && !str[0])
		return (1);
	while (str && str[++i])
	{
		if (str[i] == c)
			com++;
	}
	return (com);
}

//QUITA EL ESPACIO SOBRANTE DE LOS COMANDOS ESTILO AWK Y SED
char	*del_space(char *str, char c)
{
	int		i;
	int		len;
	char	*result;	

	i = -1;
	len = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] != c)
			len++;
		i++;
	}
	result = malloc(sizeof(char *) * len + 1);
	i = -1;
	len = 0;
	while (str[i])
	{
		if (str[i] != c)
			result[len++] = str[i];
		i++;
	}
	free(str);
	return (result);
}
