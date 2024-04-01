/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   archive_cmd_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 17:17:15 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/01 15:43:39 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

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

static char	*prepare(t_pipex *str_ppx, char **env, char **comand, int index)
{
	char	*dir_cmd;
	char	*aux;
	int		i;

	i = 0;
	index = srch_path(env);
	str_ppx->path_seg = ft_split(env[index], ':');
	dir_cmd = ft_strjoin(str_ppx->path_seg[i], "/");
	aux = ft_strdup(dir_cmd);
	dir_cmd = ft_strjoin(aux, comand[0]);
	free(aux);
	return (dir_cmd);
}

char	*search_comand(t_pipex *str_ppx, char **env, char **comand)
{
	int		i;
	int		index;
	char	*dir_cmd;
	char	*aux;
	char	*result;

	i = -1;
	index = srch_path(env);
	dir_cmd = prepare(str_ppx, env, comand, index);
	while (str_ppx->path_seg[(++i)] != 0)
	{
		dir_cmd = ft_strjoin(str_ppx->path_seg[i], "/");
		aux = ft_strdup(dir_cmd);
		free(dir_cmd);
		dir_cmd = ft_strjoin(aux, comand[0]);
		free(aux);
		if (access(dir_cmd, F_OK) >= 0)
		{
			result = ft_strdup(dir_cmd);
			free(dir_cmd);
			return (result);
		}
		free(dir_cmd);
	}
	return (NULL);
}

//POR CULPA DE LA NORMINETTE
static int	start_hd(t_pipex *str_ppx)
{
	int	start;

	if (str_ppx->here_doc != NULL)
		start = 3;
	else
		start = 2;
	return (start);
}

//RECOLECTAR LOS COMANDOS EN UNA ARRAY TRIDIMENSIONAL
void	re_cmd(t_pipex *str_ppx, char **argv)
{
	int	i;
	int	start;

	i = -1;
	start = start_hd(str_ppx);
	str_ppx->comands = malloc(sizeof(char **) * str_ppx->cant_cmd + 1);
	while ((++i) < str_ppx->cant_cmd)
	{
		if (special_case(argv[start + i], "awk") == 0
			|| special_case(argv[start + i], "sed") == 0)
		{
			if (ft_chrcnt(argv[start + i], '\'') != 2)
			{
				ft_putendl_fd("Error, Comando mal introducido", 2);
				exit(EXIT_FAILURE);
			}
			str_ppx->comands[i] = ft_split(argv[start + i], '\'');
			str_ppx->comands[i][0] = del_space(str_ppx->comands[i][0], ' ');
		}
		str_ppx->comands[i] = ft_split(argv[start + i], ' ');
	}
	if (str_ppx->here_doc != NULL)
		get_text_herdoc(str_ppx);
}
