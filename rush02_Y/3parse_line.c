/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3parse_line.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:33:47 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/22 20:55:20 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

/*
 * Skips spaces and tabs in the string starting from index 'i'.
 * Returns the new index after skipping.
 */
int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	return (i);
}

/*
 * Copies a substring from 'str' starting at 'start' and ending at 'end'.
 * Allocates memory for the new string and returns it.
 */
char	*copy_substring(char *str, int start, int end)
{
	char	*substr;
	int		len;
	int		i;

	len = end - start;
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	i = 0;
	while (i < len)
	{
		substr[i] = str[start + i];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}

/*
 * Parses the value (string part) from the line.
 * Uses the current index 'i' and updates it to the end of the line.
 * Returns 1 on success, 0 on failure.
 */
int	parse_value(char *line, int *i, char **value_part)
{
	int	start;
	int	end;

	*i = skip_spaces(line, *i);
	start = *i;
	while (line[*i] != '\0')
		(*i)++;
	end = *i;
	while (end > start && (line[end - 1] == ' ' || line[end - 1] == '\t'))
		end--;
	if (end <= start)
		return (0);
	*value_part = copy_substring(line, start, end);
	if (!*value_part)
		return (0);
	return (1);
}

/*
 * Parses the key (number part) from the line.
 * Updates the index 'i' to the position after the colon.
 * Returns 1 on success, 0 on failure.
 */
int	parse_key(char *line, int *i, char **key_part)
{
	int	start;
	int	end;

	*i = skip_spaces(line, *i);
	if (line[*i] == '\0' || (line[*i] < '0' || line[*i] > '9'))
		return (0);
	start = *i;
	while (line[*i] >= '0' && line[*i] <= '9')
		(*i)++;
	end = *i;
	*i = skip_spaces(line, *i);
	if (line[*i] != ':')
		return (0);
	(*i)++;
	*key_part = copy_substring(line, start, end);
	if (!*key_part)
		return (0);
	return (1);
}

/*
 * Parses a line from the dictionary file.
 * Extracts the key and value, and stores them in the provided entry.
 * Returns 1 on success, 0 on failure.
 */
int	parse_line(char *line, t_dict_entry *entry)
{
	int		i;
	char	*key_part;
	char	*value_part;

	i = 0;
	if (!parse_key(line, &i, &key_part))
		return (0);
	if (!parse_value(line, &i, &value_part))
	{
		free(key_part);
		return (0);
	}
	entry->key = key_part;
	entry->value = value_part;
	return (1);
}
