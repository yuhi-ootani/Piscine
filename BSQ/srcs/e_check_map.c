/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_check_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 08:41:27 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 23:33:02 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

int	check_symbol(char *line, t_map_info *map_info,
		unsigned long long line_length)
{
	unsigned long long	i;

	i = 0;
	while (i < line_length)
	{
		if (line[i] != map_info->empty && line[i] != map_info->obstacle)
			return (0);
		i++;
	}
	return (1);
}

int	is_valid_symbol(char a, char b, char c)
{
	if (!((a >= ' ' && a <= '~') && (b >= ' ' && b <= '~') && (c >= ' '
				&& c <= '~')))
		return (0);
	if (a == b || b == c || c == a)
		return (0);
	return (1);
}

unsigned long long	is_valid_number(const char *str)
{
	unsigned long long	number;

	number = 0;
	if (*str == '\0')
		return (0);
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		number = number * 10 + (*str - '0');
		str++;
	}
	return (number);
}

int	parse_first_line(char *line, t_map_info *map_info)
{
	size_t	len;
	char	*line_copy;

	len = ft_strlen(line);
	if (len < 4)
		return (0);
	line_copy = ft_strdup(line);
	if (!line_copy)
		return (0);
	map_info->empty = line[len - 3];
	map_info->obstacle = line[len - 2];
	map_info->full = line[len - 1];
	line_copy[len - 3] = '\0';
	map_info->rows = is_valid_number(line_copy);
	if (map_info->rows == 0 || !is_valid_symbol(map_info->empty,
			map_info->obstacle, map_info->full))
	{
		free(line_copy);
		return (0);
	}
	free(line_copy);
	return (1);
}

int	is_valid_map(char **map, t_map_info *map_info)
{
	unsigned long long	i;
	unsigned long long	j;
	size_t				line_length;

	if (!map[0] || !map[1] || !parse_first_line(map[0], map_info))
		return (0);
	line_length = ft_strlen(map[1]);
	if (line_length == 0)
		return (0);
	i = 1;
	while (i <= map_info->rows)
	{
		if (!map[i])
			return (0);
		if (ft_strlen(map[i]) != line_length)
			return (0);
		j = 0;
		if (!check_symbol(map[i], map_info, line_length))
			return (0);
		i++;
	}
	return (1);
}
