/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:51:17 by mcarnere          #+#    #+#             */
/*   Updated: 2024/04/20 14:51:21 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

void print_list(t_list *lst) {
    while (lst) {
        printf("%p -> ", lst->content);
        lst = lst->next;
    }
    printf("NULL\n");
}

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

int main() {
    t_list *lst = NULL;
    t_list *new_node;

    // Test with NULL list pointer
    ft_lstadd_front(&lst, NULL);
    printf("List after adding NULL node: ");
    print_list(lst);

    // Test with NULL new node
    new_node = ft_lstnew(NULL);
    ft_lstadd_front(&lst, new_node);
    printf("List after adding NULL content node: ");
    print_list(lst);

    // Test with non-NULL list and new node
    new_node = ft_lstnew((void *)1);
    ft_lstadd_front(&lst, new_node);
    printf("List after adding non-NULL node: ");
    print_list(lst);

    // Test with multiple additions
    for (int i = 2; i <= 5; i++) {
        new_node = ft_lstnew((void *)i);
        ft_lstadd_front(&lst, new_node);
    }
    printf("List after adding multiple nodes: ");
    print_list(lst);

    // Free the list
    while (lst) {
        t_list *tmp = lst;
        lst = lst->next;
        free(tmp);
    }

    return 0;
}
*/
