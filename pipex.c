/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:49:17 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/02 11:24:21 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

//ERROR
int	ft_errors(void)
{
	write(2, "Error\n", ft_strlen("Error"));
	return (1);
}

//ALGUNOS CASOS DE ERROR
int	case_error(t_pipex *str_ppx)
{
	if (str_ppx->fd_i == -1 || str_ppx->fd_o == -1)
		return (ft_errors());
	if (!str_ppx->infile || !str_ppx->outfile
		|| !str_ppx->comand_f || !str_ppx->comand_s)
		return (ft_errors());
	return (0);
}

static int	father_child(pid_t	pid, t_pipex *str_ppx, char *index, char **env)
{
	if (pid == CHILD)
	{
		index = search_comand(str_ppx, env, str_ppx->comand_f);
		if (index == NULL)
		{
			ft_putendl_fd ("Error, comando no encontrado", 2);
			return (1);
		}
		process_execve(str_ppx, env, index, CHILD);
	}
	else
	{
		waitpid(pid, &str_ppx->status, 0);
		index = search_comand(str_ppx, env, str_ppx->comand_s);
		if (index == NULL)
		{
			ft_putendl_fd ("Error, comando no encontrado", 2);
			return (1);
		}
		process_execve(str_ppx, env, index, FATHER);
	}
	return (0);
}

//INIZIALIZA LA ESTRUCTURA
static t_pipex	*start_struc(char **argv)
{
	int		i;
	t_pipex	*str_ppx;

	i = 1;
	str_ppx = ft_calloc(1, sizeof(t_pipex));
	str_ppx->infile = argv[i];
	str_ppx->fd_i = open(argv[i], O_RDONLY);
	i++;
	str_ppx->comand_f = ft_split(argv[i], ' ');
	i++;
	str_ppx->comand_s = ft_split(argv[i], ' ');
	i++;
	str_ppx->outfile = argv[i];
	str_ppx->fd_o = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	str_ppx->status = 0;
	return (str_ppx);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*str_ppx;
	char	*index;
	pid_t	pid;

	if (argc == 5)
	{
		index = NULL;
		str_ppx = start_struc(argv);
		if (case_error(str_ppx) == 1)
			exit(EXIT_FAILURE);
		pipe(str_ppx->fd);
		pid = fork();
		if (pid < 0)
			return (ft_errors());
		father_child(pid, str_ppx, index, env);
	}
	else
		return (ft_errors());
	exit(EXIT_SUCCESS);
}
