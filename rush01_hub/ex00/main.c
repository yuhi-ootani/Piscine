/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:08:18 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/15 18:31:55 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>

// check_visibility.c
int		ft_check_visibility(int grid[4][4], char *input);

// print a solution
void	ft_print_grid(int grid[4][4])
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (i < 4)
	{
		j = 0;
		while (j < 4)
		{
			c = grid[i][j] + '0';
			write(1, &c, 1);
			if (j != 3)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}

// check row and col whether num is not duplicated
int	ft_is_safe(int grid[4][4], int row, int col, int num)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (grid[row][i] == num || grid[i][col] == num)
			return (0);
		i++;
	}
	return (1);
}

// after finish col(=4), go to the next row
// check num can be put (no duplication)
// check grid whether input is same as grid
// when find a solution return 1
// if grid set is invalid, reset and retry (backtrack)
// return 0 if no solution
int	ft_solve(int grid[4][4], int row, int col, char *input)
{
	int	num;

	if (row == 4)
		return (ft_check_visibility(grid, input));
	if (col == 4)
		return (ft_solve(grid, row + 1, 0, input));
	num = 1;
	while (num <= 4)
	{
		if (ft_is_safe(grid, row, col, num))
		{
			grid[row][col] = num;
			if (ft_solve(grid, row, col + 1, input))
				return (1);
			grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

// check input valid
int	ft_validate_input(char *input)
{
	int	i;
	int	count;

	if (input == NULL)
		return (0);
	i = 1;
	count = 0;
	if (input[0] >= '1' && input[0] <= '4')
		count++;
	else
		return (0);
	while (input[i])
	{
		if ((input[i] >= '1' && input[i] <= '4') && input[i - 1] == ' ')
			count++;
		else if (input[i] != ' ')
			return (0);
		else if (input[i] == ' ' && input[i - 1] == ' ')
			return (0);
		i++;
	}
	return (count == 16 && i == 31);
}

//①check input valid
//②search a solution at ft_solve function
//③output a solution or error message
int	main(int argc, char **argv)
{
	int	grid[4][4];
	int	*p;
	int	i;

	if (argc != 2 || !ft_validate_input(argv[1]))
	{
		write(1, "input is not valid\n", 19);
		return (1);
	}
	p = &grid[0][0];
	i = 0;
	while (i < 16)
	{
		p[i] = 0;
		i++;
	}
	if (!ft_solve(grid, 0, 0, argv[1]))
	{
		write(1, "There isn\'t answer\n", 19);
		return (1);
	}
	ft_print_grid(grid);
	return (0);
}
