/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 14:51:17 by mcarnere          #+#    #+#             */
/*   Updated: 2024/04/21 14:42:44 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
#include <stdio.h>

#TESTER FOR FT_LSADD_FRONT

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

#TESTER FOR FT_LSTNEW

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

#Tester for FT_LSTSIZE

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
