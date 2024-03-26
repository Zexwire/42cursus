/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 17:23:15 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/26 18:19:59 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *) malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
/*
#include <stdio.h>

int main() {
    // Test with NULL content
    t_list *node = ft_lstnew(NULL);
    if (node == NULL) {
        printf("Failed to create node with NULL content.\n");
    } else {
        printf("Successfully created node with NULL content.\n");
        free(node);
    }

    // Test with non-NULL content
    int content = 42;
    node = ft_lstnew(&content);
    if (node == NULL) {
        printf("Failed to create node with non-NULL content.\n");
    } else {
        printf("Successfully created node with non-NULL content.\n");
        free(node);
    }

    return (0);
}
*/