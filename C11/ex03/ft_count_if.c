int ft_count_if(char **tab, int length, int(*f)(char*))
{
    int count;
    int i;

    count = 0;
    i = -1;
    while (++i < length)
        if (f(tab[i]))
            ++count;
    return (count);
}
