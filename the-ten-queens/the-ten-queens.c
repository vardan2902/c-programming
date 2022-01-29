#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int ft_ten_queens_puzzle(void);
int ft_check(int **board, int x, int y);
int ft_solution(int **board, int x, int *total_count);
void ft_print_solution(int **board);
void ft_putnbr(int nbr);

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
    int total_count;
    int i, j;
    int **board;

    total_count = 0;

    board = (int **)malloc(10 * sizeof (int *));
    i = -1;
    while(++i < 10)
    {
        board[i] = (int *)malloc(10 * sizeof (int));
        j = -1;
        while (++j < 10)
            board[i][j] = 0;
    }

    ft_solution(board, 0, &total_count);
    free(board);
    return total_count;
}

int ft_solution(int **board, int x, int *total_count)
{
    int y = -1;
	while (++y < 10)
	{
		board[x][y] = 1;
		if (ft_check(board, x, y))
		{
            if (x < 9) ft_solution(board, x + 1, total_count);

			if (x == 9) {
                ft_print_solution(board);
                *total_count = *total_count + 1;    
            }
            board[x][y] = 0;
		} 
        else 
            board[x][y] = 0;       
	}
	return (0);
}

int ft_check(int **board, int x, int y)
{
    int i;

    i = -1;
    while (++i < 10)
    {
        if (board[i][y] && x != i) return (0);
        if (board[x][i] && y != i) return (0);
        if (i)
        {
            if (x - i >= 0 && y - i >= 0)
                if (board[x - i][y - i]) return (0);
            if (x + i < 10 && y + i < 10)
                if (board[x + i][y + i]) return (0);
            if (x - i >= 0 && y + i < 10)
                if (board[x - i][y + i]) return (0);
            if (x + i < 10 && y - i >= 0)
                if (board[x + i][y - i]) return (0);
        }
       
    }
    return (1);
}

void ft_print_solution(int **board)
{
    int i, j;

    i = -1;
    while (++i < 10)
    {
        j = -1;
        while (++j < 10)
        {
            if (board[i][j] == 1)
            {
                char position = j + 48;
                write(1, &position, 1);
            }
        }   
    }
    write(1, "\n", 1);
}

void ft_putnbr(int nbr)
{
    if (nbr / 10 != 0)
        ft_putnbr(nbr / 10);
    char mod = nbr % 10 + 48;
    write(1, &mod, 1);
}