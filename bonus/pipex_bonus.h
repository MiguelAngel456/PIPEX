/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 18:12:22 by mfuente-          #+#    #+#             */
/*   Updated: 2024/04/01 14:46:13 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

//PARA FACILITAR LA LECTURA DEL CODIGO
# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

# define READ	0
# define WRITE	1

# define CHILD 	0
# define FATHER 1

//LIBRERIAS NECESARIAS
# include <stdarg.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdbool.h>

//ESTRUCTURA DE DATOS
typedef struct s_pipex
{
	int		fd_i; //FD DEL ARCHIVO DE ENTRADA (INFILE)
	int		fd_o; //FD DEL ARCHIVO DE SALIDA (OUTFILE)
	int		fd[2]; //FD DE LA FUNCION PIPE
	int		hdfd[2]; //FD CON EL CONTENIDO DEL HERE_DOC
	int		cant_cmd; //CANTIDAD DE COMANDOS
	int		status; //LO QUE ACABARA DEVOLVIENDO EL PROGRAMA;
	char	***comands; //ARRAY TRIDIMENSIONAL PARA GUARDAR TODOS LOS COMANDOS
	char	**path_seg; //VARIABLE DE ENTORNO, SEGMENTADA
	char	*infile; //ARCHIVO DE ENTRADA
	char	*outfile; //ARCHIVO DE SALIDA
	char	*here_doc; //PALABRA PARA PARAR 
}	t_pipex; //APODO

//FUNCIONES
char	*search_comand(t_pipex *str_ppx, char **env, char **comand);
void	free_matrix(char **matrix);
void	process_child(t_pipex *str_ppx, char **env, char *index, int orden);
void	re_cmd(t_pipex *str_ppx, char **argv);
void	get_text_herdoc(t_pipex *str_ppx);
void	close_archive(t_pipex	*str_ppx);
int		ft_errors(void);
int		case_error(t_pipex *str_ppx);
int		ft_chrcnt(char *str, char c);
int		special_case(char *command, char *s);
char	*del_space(char *str, char c);
void	help_normi_hd(t_pipex *str_ppx, int argc);
#endif