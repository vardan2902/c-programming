int ft_is_sort(int *tab, int length, int(*f)(int, int))
{
    int i;
    int order;
    int current;

    order = 0;
    i = -1;
    while (++i < length - 1)
    {
        if (!order)
            order = f(tab[i], tab[i + 1]);
        else
        {
            current = f(tab[i], tab[i + 1]);
            if ((order < 0 && current > 0)
                || (order > 0 && current < 0))
                return (0);
        }
    }
    return (1);
}
