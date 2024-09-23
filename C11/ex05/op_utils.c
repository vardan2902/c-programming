int get_operator_index(char *op)
{
    if (op[1] != '\0')
        return (-1);
    if (op[0] == '+')
    	return (0);
    if (op[0] == '-')
    	return (1);
    if (op[0] == '*')
	return (2);
    if (op[0] == '/')
    	return (3);
    if (op[0] == '%')
    	return (4);
    return (-1);
}
