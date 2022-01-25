#include <unistd.h>
#include <stdlib.h>


void	ft_print_board(int **board, int size);
int	**ft_init_rules(char *str, int **rules, int *size);
void	ft_initialize_board(int **board, int size);
int	ft_strlen(char *str);
int	ft_check(int x, int y, int **board, int size, int **rules);
int ft_sky_scraper(int **board, int size, int x, int y, int **rules);
int	ft_check_left_right(int x, int **board, int size, int **rules);
int	ft_check_up_down(int y, int **board, int size, int **rules);

int	main(int argc, char **argv)
{
	int	**board;
	int	i;
    int	j;
	int **rules = 0;
	int size;

	if (argc < 2)
		return (0);

	rules = ft_init_rules(argv[1], rules, &size);
	if(!rules)
		return (0);

	board = (int **)malloc(size * sizeof (int *));
	i = -1;
	while (++i < size)
		board[i] = (int *)malloc(size * sizeof (int));
	ft_initialize_board(board, size);
	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			ft_sky_scraper(board, size, i, j, rules);
	}
	ft_print_board(board, size);
	return (0);
}

int	ft_check_up_down(int y, int **board, int size, int **rules)
{
	int i = -1;
	int max = 0;
	int counter = 0;
	
	while (++i < size)
	{		
		if(max < board[i][y])
		{
			max = board[i][y];
			counter++; 
		} 		
	}
	if(counter != rules[0][y])
		return (0);
	i = size;
	max = 0;
	counter = 0;
	while (--i >= 0)
	{		
		if(max < board[i][y])
		{
			max = board[i][y];
			counter++; 
		} 		
	}
	if(counter != rules[1][y])
		return (0);
	return (1);
}

int	ft_check_left_right(int x, int **board, int size, int **rules)
{
	int i = -1;
	int max = 0;
	int counter = 0;
	
	while (++i < size)
	{	
		if(max < board[x][i])
		{
			max = board[x][i];
			counter++; 
		}
	}

	if(counter != rules[2][x])
		return (0);
	i = size;
	max = 0;
	counter = 0;
	while (--i >= 0)
	{		
		if(max < board[x][i])
		{
			max = board[x][i];
			counter++; 
		} 		
	}
	if(counter != rules[3][x])
		return (0);
	return (1);
}

int	ft_check(int x, int y, int **board, int size, int **rules)
{
	int	i;

	i = -1;
	while (++i < size)
		if (board[i][y] == board[x][y] && i != x && board[i][y] != 0)
			return (0);
	i = -1;
	while (++i < size)
		if (board[x][i] == board[x][y] && i != y && board[x][i] != 0)
			return (0);
	if (x == size - 1)
		if (!ft_check_up_down(y, board, size, rules))
			return (0);
	if (y == size - 1)
		if (!ft_check_left_right(x, board, size, rules))
			return (0);	
	return (1);
}

void	ft_initialize_board(int **board, int size)
{
	int i;
	int j;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
			board[i][j] = 0;
	}
}

int ft_sky_scraper(int **board, int size, int x, int y, int **rules)
{
	int	value;
	int	is_end;

	value = 0;
	while (++value <= size)
	{

		board[x][y] = value;
		if (ft_check(x, y, board, size, rules))
		{
			if (y + 1 < size)
				is_end = ft_sky_scraper(board, size, x, y + 1, rules);
			else if (x + 1 < size)
				is_end = ft_sky_scraper(board, size, x + 1, 0, rules);
			else
				return (1);
			if (is_end)
				return (1);
		}
	}
	board[x][y] = 0;
	return (0);
}

void	ft_print_board(int **board, int size)
{
	int	i;
	int	j;
	char val;

	i = -1;
	while (++i < size)
	{
		j = -1;
		while (++j < size)
		{
			val = board[i][j] + 48;
			write(1, &val, 1);
		}
		write(1, "\n", 1);
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i / 2 + 1);
}

int	**ft_init_rules(char *str, int **rules, int *size)
{
	int len = ft_strlen(str);
	int mod = len % 4;
	int counter;
	int i;
	int j;

	*size = len / 4;
	rules = (int **)malloc(*size * sizeof (int *));
	i = -1;
	while (++i < *size)
		rules[i] = (int *)malloc(*size * sizeof (int));
	

	if (mod == 0 && *size >= 4 && *size <= 9)
	{
		i = 0;
		counter = 0;
		while (i < 4)
		{
			j = 0;
			while (j < *size)
			{
				rules[i][j] = str[counter] - 48;
				counter += 2;
				++j;	
			}
			++i;
		}
		return (rules);
	} else {
		return (0);
	}
}

