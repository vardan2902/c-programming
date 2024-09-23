#include <unistd.h>

int add(int a, int b);
int sub(int a, int b);
int mul(int a, int b);
int div(int a, int b);
int mod(int a, int b);
int get_operator_index(char *op);

void	ft_putstr(char *str)
{
    while (*str)
        write(1, str++, 1);
}
// bring ft_putnbr, ft_atoi

void print_op_result(int a, int b, int op_index, int(*operations[5])(int, int))
{
    if (op_index == -1)
        ft_putnbr(0);
    else if (op_index == 3 && b == 0)
    	ft_putstr("Stop : division by zero");
    else if (op_index == 4 && b == 0)
    	ft_putstr("Stop : modulo by zero");
    else
        ft_putnbr(operations[op_index](a, b));
    write(1, "\n", 1);
}

int main(int argc, char **argv)
{
    int (*operations[5])(int, int);
    int a;
    int b;
    int op_index;

    operations[0] = &add;
    operations[1] = &sub;
    operations[2] = &mul;
    operations[3] = &div;
    operations[4] = &mod;
    if (argc != 4)
        return (0);
    a = ft_atoi(argv[1]);
    b = ft_atoi(argv[3]); 
    op_index = get_operator_index(argv[2]);
    print_op_result(a, b, op_index, operations);
    return (0);
}
