/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_split_into_lines.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 17:02:20 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 23:32:41 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	count_lines(char *str)
{
	int	lines;
	int	i;

	lines = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			lines++;
		i++;
	}
	return (lines);
}

char	**allocate_lines(char *str)
{
	int		line_count;
	char	**map;

	line_count = count_lines(str);
	map = (char **)malloc(sizeof(char *) * (line_count + 1));
	if (!map)
		return (NULL);
	return (map);
}

void	copy_lines(char **map, char *str)
{
	int	i;
	int	start;
	int	line_len;
	int	line_index;

	i = 0;
	start = 0;
	line_index = 0;
	while (str[i])
	{
		if (str[i] == '\n')
		{
			line_len = i - start;
			map[line_index] = (char *)malloc(sizeof(char) * (line_len + 1));
			if (!map[line_index])
				return ;
			ft_strncpy(map[line_index], str + start, line_len);
			map[line_index][line_len] = '\0';
			line_index++;
			start = i + 1;
		}
		i++;
	}
	map[line_index] = NULL;
}

char	**split_into_lines(char *str)
{
	char	**map;

	map = allocate_lines(str);
	if (!map)
		return (NULL);
	copy_lines(map, str);
	return (map);
}
