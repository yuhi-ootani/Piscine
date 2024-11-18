/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_read_map_stdin.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/24 09:41:45 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 23:31:59 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

char	*cpy_buffer(char *buffer, char *new_buffer, size_t total_size)
{
	size_t	i;

	i = 0;
	while (i < total_size)
	{
		new_buffer[i] = buffer[i];
		i++;
	}
	free(buffer);
	return (new_buffer);
}

char	*if_expand_buf(char *buffer, size_t *buffer_size, size_t *total_size,
		ssize_t *bytes_read)
{
	char	*new_buffer;

	*total_size += *bytes_read;
	if (*total_size >= *buffer_size)
	{
		*buffer_size *= 2;
		new_buffer = malloc(*buffer_size);
		if (!new_buffer)
		{
			write(1, "failed to malloc new_buffer\n", 28);
			free(buffer);
			return (NULL);
		}
		buffer = cpy_buffer(buffer, new_buffer, *total_size);
	}
	return (buffer);
}

char	*read_stdin(void)
{
	char	*buffer;
	size_t	buf_size;
	size_t	total_size;
	ssize_t	bytes_read;

	buffer = malloc(INITIAL_BUFFER_SIZE);
	if (!buffer)
		return (NULL);
	buf_size = INITIAL_BUFFER_SIZE;
	total_size = 0;
	bytes_read = read(0, buffer + total_size, buf_size - total_size);
	while (bytes_read > 0)
	{
		buffer = if_expand_buf(buffer, &buf_size, &total_size, &bytes_read);
		if (!buffer)
			return (NULL);
		bytes_read = read(0, buffer + total_size, buf_size - total_size);
	}
	if (bytes_read == -1)
	{
		free(buffer);
		return (NULL);
	}
	buffer[total_size] = '\0';
	return (buffer);
}
