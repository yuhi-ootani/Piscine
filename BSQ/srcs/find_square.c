/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_square.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 17:44:47 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 23:33:14 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	map_square(char **map, t_map_info *map_info)
{
	int	i;
	int	j;

	i = map_info->max_x - map_info->max_size + 1;
	while (i <= map_info->max_x)
	{
		j = map_info->max_y - map_info->max_size + 1;
		while (j <= map_info->max_y)
		{
			map[i + 1][j] = map_info->full;
			j++;
		}
		i++;
	}
}

void	process_row(int **dp, int i, char **map, t_map_info *map_info)
{
	int	j;

	j = 0;
	while (j < map_info->cols)
	{
		if (map[i + 1][j] == map_info->obstacle)
			dp[i][j] = 0;
		else if (i == 0 || j == 0)
			dp[i][j] = 1;
		else
			dp[i][j] = ft_min_of_three(dp[i - 1][j], dp[i][j - 1], dp[i - 1][j
					- 1]) + 1;
		if (dp[i][j] > map_info->max_size)
		{
			map_info->max_size = dp[i][j];
			map_info->max_x = i;
			map_info->max_y = j;
		}
		j++;
	}
}

void	fill_dp(char **map, int **dp, t_map_info *map_info)
{
	unsigned long long	i;

	i = 0;
	while (i < map_info->rows)
	{
		process_row(dp, i, map, map_info);
		i++;
	}
	map_square(map, map_info);
}

int	**malloc_dp(int rows, int cols)
{
	int	**dp;
	int	i;
	int	j;

	dp = (int **)malloc(sizeof(int *) * rows);
	if (!dp)
		return (NULL);
	i = 0;
	while (i < rows)
	{
		dp[i] = (int *)malloc(sizeof(int) * cols);
		if (!dp[i])
		{
			free_dp(dp, i);
			return (NULL);
		}
		j = 0;
		while (j < cols)
		{
			dp[i][j] = 0;
			j++;
		}
		i++;
	}
	return (dp);
}

void	find_square(char **map, t_map_info *map_info)
{
	int	**dp;

	map_info->cols = ft_strlen(map[1]);
	dp = malloc_dp(map_info->rows, map_info->cols);
	if (!dp)
		return ;
	fill_dp(map, dp, map_info);
	free_dp(dp, map_info->rows);
}
