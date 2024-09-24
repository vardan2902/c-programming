#include "ft_list.h"

void    ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
    t_list  *temp;

    while (begin_list)
    {
        temp = begin_list->next;
        if (free_fct)
            free_fct(begin_list->data);
        free(begin_list);
        begin_list = temp;
    }
}
