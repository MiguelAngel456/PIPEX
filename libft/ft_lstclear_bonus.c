/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfuente- <mfuente-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/08 10:34:33 by mfuente-          #+#    #+#             */
/*   Updated: 2023/12/08 19:04:47 by mfuente-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*temp;

	temp = *lst;
	if (!*lst || !lst || !del)
		return ;
	else
	{
		while ((*lst) != NULL)
		{
			temp = (*lst)->next;
			ft_lstdelone((*lst), del);
			(*lst) = temp;
		}
	}
}
