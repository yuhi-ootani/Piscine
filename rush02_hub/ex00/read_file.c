/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:45:00 by ktei              #+#    #+#             */
/*   Updated: 2024/09/25 12:15:55 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

int	get_file_size(const char *filename)
{
	int		fd;
	int		bytes_read;
	int		total_size;
	char	buffer[1024];

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (-1);
	total_size = 0;
	bytes_read = read(fd, buffer, 1024);
	while (bytes_read > 0)
	{
		total_size += bytes_read;
		bytes_read = read(fd, buffer, 1024);
	}
	if (bytes_read == -1)
	{
		close(fd);
		write(1, "Error\n", 6);
		return (-1);
	}
	close(fd);
	return (total_size);
}

char	*read_file_content(const char *filename, int total_size)
{
	int		fd;
	char	*file_content;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (NULL);
	file_content = (char *)malloc(total_size + 1);
	if (!file_content)
	{
		close(fd);
		return (NULL);
	}
	bytes_read = read(fd, file_content, total_size);
	if (bytes_read == -1)
	{
		free(file_content);
		close(fd);
		return (NULL);
	}
	file_content[bytes_read] = '\0';
	close(fd);
	return (file_content);
}

char	*read_file_to_string(const char *filename)
{
	int		total_size;
	char	*file_content;

	total_size = get_file_size(filename);
	if (total_size == -1)
	{
		write(1, "Error\n", 6);
		return (NULL);
	}
	file_content = read_file_content(filename, total_size);
	if (!file_content)
		write(1, "Erro\nr", 6);
	return (file_content);
}
