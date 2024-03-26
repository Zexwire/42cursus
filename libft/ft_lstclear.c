/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 20:58:28 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/26 21:18:58 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ptr;
	t_list	*aux;

	if (!lst)
		return ;
	ptr = *lst;
	while (ptr)
	{
		aux = ptr->next;
		ft_lstdelone(ptr, del);
		ptr = aux;
	}
}
