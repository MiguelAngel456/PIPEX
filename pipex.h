/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:12:22 by mfuente-          #+#    #+#             */
/*   Updated: 2024/03/13 17:44:05 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

# define READ    0
# define WRITE   1

# define CHILD 0
# define FATHER 1

//LIBRERIAS NECESARIAS
# include <stdarg.h>
# include "./libft/libft.h"
# include <fcntl.h>
# include <stdlib.h>

//LISTAS ENLANZADAS (DATOS DEL MAPA)
typedef struct s_pipex
{
	int		fd_i; //FD DEL ARCHIVO DE ENTRADA (INFILE)
	int		fd_o; //FD DEL ARCHIVO DE SALIDA (OUTFILE)
	int		fd[2]; //FD DE LA FUNCION PIPE
	int		status; //LO QUE ACABARA DEVOLVIENDO EL PROGRAMA;
	char	**comand_f; //ARRAY CON EL PRIMER COMANDO
	char	**comand_s; //ARRAY CON EL SEGUNDO COMANDO
	char	**path_seg; //VARIABLE DE ENTORNO, SEGMENTADA
	char	*infile; //ARCHIVO DE ENTRADA
	char	*outfile; //ARCHIVO DE SALIDA
}	t_pipex; //APODO

//FUNCIONES
void	free_matrix(char **matrix);
void	process_execve(t_pipex	*str_ppx, char **env, char *index, int tipo);
char	*search_comand(t_pipex *str_ppx, char **env, char **comand);

#endif