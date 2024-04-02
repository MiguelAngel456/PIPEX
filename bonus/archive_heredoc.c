/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_heredoc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:19:50 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/02 11:04:53 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	ft_strstr(t_pipex *str_ppx, char *escrito)
{
	int	i;

	i = 0;
	while (i < (int)ft_strlen(str_ppx->here_doc))
	{
		if (str_ppx->here_doc[i] != escrito[i])
			return (1);
		i++;
	}
	return (0);
}

static void	error_pipe(void)
{
	ft_putendl_fd("Error en hdfd", 2);
	exit(EXIT_FAILURE);
}

// SACAR EL TEXTO DEL HERE_DOC
// LEE UNA LINEA DEL USUARIO
// LA ESCRIBE EN EL FD DEL PIPE
// COMPRUEBA SI DEBE CONTINUAR
void	get_text_herdoc(t_pipex *str_ppx)
{
	bool	continuar;
	char	*buffer;

	if (pipe(str_ppx->hdfd) == -1)
		error_pipe();
	continuar = true;
	while (continuar == true)
	{
		ft_putstr_fd("> ", 1);
		buffer = get_next_line(0);
		if (ft_strstr(str_ppx, buffer) == 0)
		{
			free(buffer);
			continuar = false;
		}
		else
		{
			write(str_ppx->hdfd[WRITE], buffer, ft_strlen(buffer));
			free(buffer);
		}
	}
	close(str_ppx->hdfd[WRITE]);
	str_ppx->fd_i = str_ppx->hdfd[READ];
}
