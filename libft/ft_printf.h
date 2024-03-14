/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 08:27:26 by mfuente-          #+#    #+#             */
/*   Updated: 2024/02/13 14:04:07 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define FT_INT_MAX 2147483647
# define FT_INT_MIN -2147483648

//LIBRERIAS NECESARIAS
# include <stdarg.h>
# include "./libft.h"

//FUNCIONES
int	ft_printf(char const *word, ...);
int	ft_printfchar(char c);
int	ft_printf_d(int num);
int	ft_printf_u(unsigned int num);
int	ft_printf_por(void);
int	ft_printf_s(char *palabra);
int	ft_printf_x(unsigned int hex);
int	ft_printf_xm(unsigned int hex);
int	ft_printf_punt(void *var);
#endif