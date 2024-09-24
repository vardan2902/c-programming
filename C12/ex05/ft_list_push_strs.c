#include "ft_list.h"

void    ft_list_push_front(t_list **begin_list, void *data)
{
    t_list  *node;

    node = ft_create_elem(data);
    if (!*begin_list)
        *begin_list = node;
    else
    {
        node->next = *begin_list;
        *begin_list = node;
    }
}

t_list  *ft_list_push_strs(int size, char **strs)
{
    int     i;
    t_list  *head;

    if (!strs || size <= 0)
        return (NULL);
    head = ft_create_elem(strs[0]);
    i = 0;
    while (++i < size)
        ft_list_push_front(&head, strs[i]);
    return (head);
}
