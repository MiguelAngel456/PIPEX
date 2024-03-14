/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:19:50 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/09 08:35:28 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	liberar_memoria(char **matr)
{
	int	i;

	i = 0;
	if (matr == NULL)
		return ;
	while (matr[i] != NULL)
	{
		free(matr[i]);
		i++;
	}
	free(matr);
}

static void	rellenar(char *palabra, char const *frase, char c)
{
	int	i;

	i = 0;
	while (frase[i] != 0 && frase[i] != c)
	{
		palabra[i] = frase[i];
		i++;
	}
	palabra[i] = '\0';
}

static void	aux(char **matr, char const *s, char c)
{
	size_t	cont_aux;
	size_t	cont_s;
	size_t	cont;

	cont_s = 0;
	cont = 0;
	while (s[cont_s])
	{
		cont_aux = 0;
		while (s[cont_aux + cont_s] != 0 && s[cont_aux + cont_s] != c)
			cont_aux++;
		if (cont_aux > 0)
		{
			matr[cont] = malloc((cont_aux + 1) * sizeof(char));
			if (!matr[cont])
				return (liberar_memoria(matr));
			rellenar(matr[cont], (s + cont_s), c);
			cont++;
			cont_s = cont_s + cont_aux;
		}
		else
			cont_s++;
	}
	matr[cont] = NULL;
}

static int	ntimes(char const *s, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && i != 0 && s[i - 1] != c)
		{
			cont++;
		}
		i++;
	}
	if (s[i - 1] != c)
		cont++;
	return (cont);
}

char	**ft_split(char const *s, char c)
{
	char	**final;
	int		palabras;

	if (s == NULL)
		return (NULL);
	palabras = ntimes(s, c);
	final = (char **)malloc((palabras + 1) * sizeof(char *));
	if (!final)
		return (NULL);
	aux(final, s, c);
	return (final);
}

/*int main (void)
{
	//ft_split(NULL, 'c');
	 ft_split(" hola ", ' ');
	 ft_split("     hola    ", ' ');
	 ft_split("    hola     adios    ", ' ');
	 ft_split("hola", ' ');
	 ft_split("   hola que tal ", '\0');
	return 0;
}*/
/*int main(void) {
   char const *input_string = "hello";
    char delimiter = ' ';
    char **result = ft_split(input_string, delimiter);
    if (result)
    {
        for (int i = 0; result[i] != NULL; i++)
        {
            printf("Word %d: %s\n", i + 1, result[i]);
            free(result[i]);
        }
        free(result);
    }
    else
    {
        printf("Error in ft_split function\n");
    }

    return 0;
}*/