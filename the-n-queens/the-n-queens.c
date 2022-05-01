#include <unistd.h>
#define N 10

int ft_ten_queens_puzzle(void);
int ft_check(int board[N][N], int x, int y);
int ft_solution(int board[N][N], int x, int *total_count);
void ft_putchar(int c);
void ft_putnbr(int nbr);
void ft_print_solution(int board[N][N]);

int main()
{
    int total_count;

    total_count = ft_ten_queens_puzzle();
    write(1, "Total count of possiblle answers is:     ", 42);
    ft_putnbr(total_count);
    write(1, "\n", 1);
    return (0);
}

int ft_ten_queens_puzzle()
{ 
    int total_count, i, j;
    int board[N][N];

    total_count = 0;
    i = -1;
    while(++i < N)
    {
        j = -1;
        while (++j < N)
            board[i][j] = 0;
    }
    ft_solution(board, 0, &total_count);
    return total_count;
}

int ft_solution(int board[N][N], int x, int *total_count)
{
    int y = -1;
	while (++y < N)
	{
		board[x][y] = 1;
		if (ft_check(board, x, y))
		{
            if (x < N - 1) ft_solution(board, x + 1, total_count);
			if (x == N - 1)
            {
                ft_print_solution(board);
                *total_count += 1;    
            }
		} 
        board[x][y] = 0;
	}
	return (0);
}

int ft_check(int board[N][N], int x, int y)
{
    int i;

    i = -1;
    while (++i < N)
    {
        if (board[i][y] && x != i) return (0);
        if (board[x][i] && y != i) return (0);
        if (x - i >= 0 && y - i >= 0 && i)
            if (board[x - i][y - i]) return (0);
        if (x - i >= 0 && y + i < N && i)
            if (board[x - i][y + i]) return (0);
    }
    return (1);
}

void ft_print_solution(int board[N][N])
{
    int i, j;

    i = -1;
    while (++i < N)
    {
        j = -1;
        while (++j < N)
            if (board[i][j] == 1) ft_putchar(j + 48);
    }
    write(1, "\n", 1);
}

void ft_putchar(int c)
{
    write(1, &c, 1);
}

void ft_putnbr(int nbr)
{
    if (nbr >= 10) ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + 48);
}