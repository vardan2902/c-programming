#include "ft_list.h"

void    ft_list_push_back(t_list **begin_list, void *data)
{
    t_list  *node;
    t_list  *temp;

    node = ft_create_elem(data);
    if (!*begin_list)
    {
        *begin_list = node;
        return ;
    }
    temp = *begin_list;
    while (temp->next)
        temp = temp->next;
    temp->next = node;
}
