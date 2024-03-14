/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:41:49 by mfuente-          #+#    #+#             */
/*   Updated: 2024/01/15 11:30:09 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

char	*ft_free(char *str)
{
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (NULL);
}

//QUITA LA PRIMERA FILA DEL TEXT
char	*new_text(char *text)
{
	char	*newt;
	char	*ptr;
	int		len;

	ptr = ft_strchr_gnl(text, '\n');
	if (!ptr)
	{
		newt = NULL;
		return (ft_free(text));
	}
	else
		len = (ptr - text) + 1;
	if (!text[len])
		return (ft_free(text));
	newt = ft_substr_gnl(text, len, ft_strlen_gnl(text) - len);
	ft_free(text);
	if (!newt)
		return (NULL);
	return (newt);
}

//SACA LA LINEA QUE NOS  INTERESA
char	*the_line(char *text)
{
	char	*line;
	char	*aux;
	int		len;

	aux = ft_strchr_gnl(text, '\n');
	len = (aux - text) + 1;
	line = ft_substr_gnl(text, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

//SACA UN BUFFER QUE CONTIENE '\N'
char	*read_text(int fd, char *text)
{
	int		allow;
	char	*buffer;

	allow = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (ft_free(text));
	buffer[0] = '\0';
	while (allow > 0 && !ft_strchr_gnl(buffer, '\n'))
	{
		allow = read(fd, buffer, BUFFER_SIZE);
		if (allow > 0)
		{
			buffer[allow] = '\0';
			text = ft_strjoin_gnl(text, buffer);
		}
	}
	ft_free(buffer);
	if (allow == -1)
		return (ft_free(text));
	return (text);
}

char	*get_next_line(int fd)
{
	static char	*text;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if ((text && !ft_strchr_gnl(text, '\n')) || !text)
		text = read_text (fd, text);
	if (!text)
		return (NULL);
	line = the_line(text);
	if (!line)
		return (ft_free(text));
	text = new_text(text);
	return (line);
}
//EXPLICACION: Declaro el static --> meto en el static la linea con \N y mas
//				 --> saco lo que me interesa de esa linea
//				Elimino la linea ya proyectada del static y 
//				dejar solo las que no han sido todavia proyectadas
/* int main() {
    int fd = open("archivo.txt", O_RDONLY);
    char *line;
	int i;

	i = 0;
    while (i < 6) {
		line = get_next_line(fd);
        printf("Línea leída %d: %s\n", i, line);
        free(line);
		i++;
    }
    close(fd);

    return 0;
} */