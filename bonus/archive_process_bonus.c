/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_process_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:23:34 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/01 15:09:29 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	close_archive(t_pipex	*str_ppx)
{
	close(str_ppx->fd_i);
	close(str_ppx->fd_o);
	close(str_ppx->fd[READ]);
	close(str_ppx->fd[WRITE]);
	close(str_ppx->hdfd[WRITE]);
}

void	process_child(t_pipex *str_ppx, char **env, char *index, int orden)
{
	if (orden < str_ppx->cant_cmd - 1)
	{
		if (dup2(str_ppx->fd[WRITE], STDOUT_FILENO) == -1)
		{
			ft_putendl_fd("Error 3", 2);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		if (dup2(str_ppx->fd_o, STDOUT_FILENO) == -1)
		{
			ft_putendl_fd("Error 7", 2);
			exit(EXIT_FAILURE);
		}
	}
	close(str_ppx->fd[READ]);
	close(str_ppx->fd[WRITE]);
	execve(index, str_ppx->comands[orden], env);
	ft_putendl_fd("Error en excve", 2);
	exit(EXIT_FAILURE);
}

//ESTA FUNCION ES PARA AYUDAR CON LA NORMI DEL MAIN REALMENTE
//NO HACE NADA IMPORTANTE
void	help_normi_hd(t_pipex *str_ppx, int argc)
{
	if (str_ppx->here_doc != NULL)
		str_ppx->cant_cmd = argc - 4;
	else
		str_ppx->cant_cmd = argc - 3;
}
