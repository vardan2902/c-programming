#include "ft_list.h"

t_list *ft_list_at(t_list *begin_list, unsigned int nbr)
{
    int i;

    i = -1;
    while (++i < nbr)
        begin_list = begin_list->next;
    return (begin_list);
}
