/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_visibility.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aryamamo <aryamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 19:07:03 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/15 18:35:00 by aryamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// count visible box and compare from left side
int	ft_check_row_left(int grid[4][4], int row, int expected)
{
	int	max_seen;
	int	visible_count;
	int	col;

	max_seen = 0;
	visible_count = 0;
	col = 0;
	while (col < 4)
	{
		if (grid[row][col] > max_seen)
		{
			max_seen = grid[row][col];
			visible_count++;
		}
		col++;
	}
	return (visible_count == expected);
}

// count visible box and compare from right side
int	ft_check_row_right(int grid[4][4], int row, int expected)
{
	int	max_seen;
	int	visible_count;
	int	col;

	max_seen = 0;
	visible_count = 0;
	col = 3;
	while (col >= 0)
	{
		if (grid[row][col] > max_seen)
		{
			max_seen = grid[row][col];
			visible_count++;
		}
		col--;
	}
	return (visible_count == expected);
}

// count visible box and compare from up side
int	ft_check_col_up(int grid[4][4], int col, int expected)
{
	int	max_seen;
	int	visible_count;
	int	row;

	max_seen = 0;
	visible_count = 0;
	row = 0;
	while (row < 4)
	{
		if (grid[row][col] > max_seen)
		{
			max_seen = grid[row][col];
			visible_count++;
		}
		row++;
	}
	return (visible_count == expected);
}

// count visible box and compare from down side
int	ft_check_col_down(int grid[4][4], int col, int expected)
{
	int	max_seen;
	int	visible_count;
	int	row;

	max_seen = 0;
	visible_count = 0;
	row = 3;
	while (row >= 0)
	{
		if (grid[row][col] > max_seen)
		{
			max_seen = grid[row][col];
			visible_count++;
		}
		row--;
	}
	return (visible_count == expected);
}

// check template solution correct
// 1, convert input(char) into expected(int)
// check visible_count == expected row by row
// once check function return 0, return 0(not correct)
int	ft_check_visibility(int grid[4][4], char *input)
{
	int	expected[16];
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i])
	{
		if (input[i] >= '1' && input[i] <= '4')
		{
			expected[j++] = input[i] - '0';
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if ((!ft_check_col_up(grid, i, expected[i]))
			|| (!ft_check_col_down(grid, i, expected[i + 4]))
			|| (!ft_check_row_left(grid, i, expected[i + 8]))
			|| (!ft_check_row_right(grid, i, expected[i + 12])))
			return (0);
		i++;
	}
	return (1);
}
