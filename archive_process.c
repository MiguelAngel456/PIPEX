/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_process.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:23:34 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/01 12:55:41 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

static void	close_archive(t_pipex	*str_ppx)
{
	if (str_ppx->fd_i != -1)
		close(str_ppx->fd_i);
	if (str_ppx->fd_o != -1)
		close(str_ppx->fd_o);
	if (str_ppx->fd[READ] != -1)
		close(str_ppx->fd[READ]);
	if (str_ppx->fd[WRITE] != -1)
		close(str_ppx->fd[WRITE]);
}

void	process_execve(t_pipex	*str_ppx, char **env, char *index, int tipo)
{
	if (tipo == CHILD)
	{
		if (dup2(str_ppx->fd_i, STDIN_FILENO) == -1
			|| dup2(str_ppx->fd[WRITE], STDOUT_FILENO) == -1)
			write(2, "Error\n", ft_strlen("Error"));
		else
		{
			execve(index, str_ppx->comand_f, env);
			ft_putendl_fd("Error", 2);
			exit (EXIT_FAILURE);
		}
		close_archive(str_ppx);
	}
	else
	{
		if (dup2(str_ppx->fd[READ], STDIN_FILENO) == -1)
			write(2, "Error\n", ft_strlen("Error"));
		if (dup2(str_ppx->fd_o, STDOUT_FILENO) == -1)
			write(2, "Error\n", ft_strlen("Error"));
		close_archive(str_ppx);
		execve(index, str_ppx->comand_s, env);
		exit(42);
	}
}
