/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:17:15 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/01 12:59:33 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_all(t_pipex *str_ppx)
{
	free_matrix(str_ppx->comand_f);
	free_matrix(str_ppx->comand_s);
	free_matrix(str_ppx->path_seg);
	free(str_ppx->outfile);
	free(str_ppx->infile);
}

static int	srch_path(char **env)
{
	int	i;

	i = 0;
	while (ft_strncmp("PATH=", env[i], 5) != 0)
	{
		i++;
	}
	return (i);
}

static char	*help_normi(char *path_seg, char *comand)
{
	char	*dir_cmd;
	char	*aux;

	dir_cmd = ft_strjoin(path_seg, "/");
	aux = dir_cmd;
	dir_cmd = ft_strjoin(dir_cmd, comand);
	free(aux);
	return (dir_cmd);
}

char	*search_comand(t_pipex *str_ppx, char **env, char **comand)
{
	int		i;
	int		index;
	char	*dir_cmd;
	char	*aux;

	i = 0;
	index = srch_path(env);
	str_ppx->path_seg = ft_split(env[index], ':');
	dir_cmd = ft_strjoin(str_ppx->path_seg[i], "/");
	aux = dir_cmd;
	dir_cmd = ft_strjoin(dir_cmd, comand[0]);
	free(aux);
	while (str_ppx->path_seg[i] != 0)
	{
		if (access(dir_cmd, F_OK) != -1)
			return (dir_cmd);
		i++;
		free(dir_cmd);
		if (str_ppx->path_seg[i] != 0)
			dir_cmd = help_normi(str_ppx->path_seg[i], comand[0]);
		else
			dir_cmd = NULL;
	}
	return (dir_cmd);
}
