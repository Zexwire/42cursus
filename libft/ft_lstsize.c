/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 18:25:42 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/26 19:08:03 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	if (!lst)
		return (0);
	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

/*
#include <stdio.h>

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

void add_node(t_list **lst, void *content) {
    t_list *new_node = ft_lstnew(content);
    if (new_node) {
        new_node->next = *lst;
        *lst = new_node;
    }
}

int main() {
    t_list *lst = NULL;

    // Test with NULL list
    int size = ft_lstsize(lst);
    printf("Size of NULL list: %d\n", size);

    // Test with empty list
    t_list *empty_list = NULL;
    size = ft_lstsize(empty_list);
    printf("Size of empty list: %d\n", size);

    // Test with single node list
    add_node(&lst, (void *)1);
    size = ft_lstsize(lst);
    printf("Size of single node list: %d\n", size);

    // Test with multiple nodes
    for (int i = 2; i <= 5; i++) {
        add_node(&lst, (void *)i);
    }
    size = ft_lstsize(lst);
    printf("Size of multiple nodes list: %d\n", size);

    // Free the list
    while (lst) {
        t_list *tmp = lst;
        lst = lst->next;
        free(tmp);
    }

    return 0;
}
*/
