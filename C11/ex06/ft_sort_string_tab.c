void    ft_sort_string_tab(char **tab)
{
    int i;
    int j;
    int min_idx;

    if (!tab)
        return ;
    i = -1;
    while (tab[++i + 1])
    {
        j = i;
        min_idx = i;
        while (tab[++j])
            if (ft_strcmp(tab[i], tab[j]) > 0)
                min_idx = j;
        ft_swap(&tab[i], &tab[min_idx]);
    }
}

// bring ft_swap, ft_strcmp
