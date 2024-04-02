/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 09:49:17 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/02 11:19:14 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	free_all(t_pipex *str_ppx)
{
	int	i;

	i = 0;
	while (i < str_ppx->cant_cmd)
	{
		free_matrix(str_ppx->comands[i]);
		i++;
	}
	free(str_ppx->comands);
}

static int	child(t_pipex *str_ppx, int orden, char **env, pid_t pid)
{
	char	*index;

	index = NULL;
	if (pid == CHILD)
	{
		index = search_comand(str_ppx, env, str_ppx->comands[orden]);
		if (index == NULL)
		{
			return (1);
		}
		else
			process_child(str_ppx, env, index, orden);
	}
	return (0);
}

//INICIALIZA LA ESTRUCTURA
static t_pipex	*start_struc(char **argv, int argc)
{
	int		i;
	t_pipex	*str_ppx;

	i = 1;
	str_ppx = ft_calloc(1, sizeof(t_pipex));
	str_ppx->infile = argv[i];
	str_ppx->here_doc = NULL;
	if (ft_strncmp("here_doc", argv[1], 7) != 0)
		str_ppx->fd_i = open(argv[i], O_RDONLY);
	if (ft_strncmp("here_doc", argv[1], 7) != 0)
		str_ppx->here_doc = NULL;
	else
		str_ppx->here_doc = argv[2];
	i += (argc - 3);
	str_ppx->outfile = argv[i];
	i++;
	if (str_ppx->here_doc == NULL)
		str_ppx->fd_o = open(argv[i], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	else
		str_ppx->fd_o = open(argv[i], O_WRONLY | O_CREAT | O_APPEND, 0777);
	str_ppx->status = 0;
	return (str_ppx);
}

static void	help_normi(t_pipex	*str_ppx, int i, char **env, pid_t	pid)
{
	pipe(str_ppx->fd);
	pid = fork();
	if (pid < 0)
		exit(EXIT_FAILURE);
	if (child(str_ppx, i, env, pid) == 1)
	{
		ft_putendl_fd("Error, comando no existe", 2);
		exit(EXIT_FAILURE);
	}
	if (dup2(str_ppx->fd[READ], STDIN_FILENO) == -1)
		exit(EXIT_FAILURE);
	close(str_ppx->fd[READ]);
	close(str_ppx->fd[WRITE]);
	waitpid(pid, NULL, 0);
}

int	main(int argc, char **argv, char **env)
{
	t_pipex	*str_ppx;
	pid_t	pid;
	int		i;

	if (argc >= 4)
	{
		i = -1;
		str_ppx = start_struc(argv, argc);
		if (case_error(str_ppx) == 1)
			exit(EXIT_FAILURE);
		help_normi_hd(str_ppx, argc);
		re_cmd(str_ppx, argv);
		if (dup2(str_ppx->fd_i, STDIN_FILENO) == -1)
			exit(EXIT_FAILURE);
		pid = 0;
		while ((++i) < str_ppx->cant_cmd)
			help_normi(str_ppx, i, env, pid);
		close_archive(str_ppx);
		free_all(str_ppx);
	}
	else
		return (ft_errors());
	exit(EXIT_SUCCESS);
}
