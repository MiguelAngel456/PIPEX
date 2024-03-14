/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 16:04:50 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/08 19:06:17 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*resultado;
	t_list	*aux;

	if (!lst || !f || !del)
		return (NULL);
	aux = 0;
	while (lst != NULL)
	{
		resultado = malloc(sizeof(t_list));
		if (!resultado)
		{
			ft_lstclear(&aux, del);
			return (NULL);
		}
		resultado->content = f(lst->content);
		resultado->next = 0;
		ft_lstadd_back(&aux, resultado);
		lst = lst->next;
	}
	return (aux);
}
