/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 14:56:52 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 14:05:07 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

//LIBRERIAS NECESARIAS
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include "./libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

//FUNCIONES
char	*get_next_line(int fd);
char	*ft_strchr_gnl(char *s, int c);
char	*ft_substr_gnl(char *s, unsigned int start, size_t len);
size_t	ft_strlen_gnl(const char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_free(char *str);

#endif	