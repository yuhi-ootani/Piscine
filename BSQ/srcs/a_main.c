/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 10:30:15 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 23:24:48 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	main_in_while(char *input_data)
{
	char				**map;
	t_map_info			map_info;
	unsigned long long	i;

	map_info = (t_map_info){.empty = 0, .obstacle = 0, .full = 0, .rows = 0,
		.cols = 0, .max_size = 0, .max_x = 0, .max_y = 0};
	map = split_into_lines(input_data);
	if (!is_valid_map(map, &map_info))
	{
		write(2, "map error\n", 10);
		free_lines(map);
		return ;
	}
	find_square(map, &map_info);
	i = 1;
	while (i <= map_info.rows)
	{
		ft_putstr(map[i]);
		write(1, "\n", 1);
		i++;
	}
	free_lines(map);
}

int	process_stdin(void)
{
	char	*input_data;

	input_data = read_stdin();
	if (!input_data)
		return (1);
	main_in_while(input_data);
	free(input_data);
	return (0);
}

int	process_files(int argc, char **argv)
{
	char	*input_data;
	int		i;

	i = 1;
	while (i < argc)
	{
		input_data = read_file_to_string(argv[i]);
		if (!input_data)
			return (1);
		main_in_while(input_data);
		free(input_data);
		if (i < argc - 1)
			write(1, "\n", 1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		if (process_stdin() != 0)
			return (1);
	}
	else
	{
		if (process_files(argc, argv) != 0)
			return (1);
	}
	return (0);
}
