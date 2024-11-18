/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2read_dictionary.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:33:47 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/22 19:39:00 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

void	read_dictionary(char *filename, t_dict_entry *dict, int *dict_size)
{
	int		fd;
	char	buffer[1024];
	int		bytes_read;
	int		i;
	char	*line;

	fd = open(filename, O_RDONLY);
	i = 0;
	if (fd == -1)
	{
		write(1, "Dict Error\n", 11);
		return ;
	}
	while ((bytes_read = read(fd, buffer, 1024)) > 0)
	{
		buffer[bytes_read] = '\0';
		line = strtok(buffer, "\n");
		while (line != NULL)
		{
			parse_line(line, &dict[i]);
			i++;
			line = strtok(NULL, "\n");
		}
	}
	*dict_size = i;
	close(fd);
}
