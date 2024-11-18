/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7.find_in_dictionary.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:33:47 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/22 20:03:32 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

// Converts an unsigned long long number to a string.
// Allocates memory dynamically and returns the string.
// Temporary buffer to store the number (maximum 20 digits+null terminator)
// Start from the end of the buffer
char	*ft_itoa(unsigned long long num)
{
	char	buffer[21];
	int		i;

	i = 20;
	buffer[i] = '\0';
	if (num == 0)
		buffer[--i] = '0';
	while (num > 0)
	{
		buffer[--i] = (num % 10) + '0';
		num /= 10;
	}
	return (ft_strdup(&buffer[i]));
}

// Searches for the corresponding English word in dictionary for given number.
// Returns the word if found, or NULL if not found.
// Convert the number to a string
const char	*find_word(unsigned long long num, t_dict_entry *dict,
		int dict_size)
{
	const char	*result = NULL;
	char		*num_str;
	int			i;

	num_str = ft_itoa(num);
	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].key, num_str) == 0)
		{
			result = dict[i].value;
			break ;
		}
		i++;
	}
	free(num_str);
	return (result);
}

// Searches for the corresponding English word
// in the dictionary using a string key.
// Returns the word if found, or NULL if not found.

char	*find_unit_by_string(const char *key_str, t_dict_entry *dict,
		int dict_size)
{
	int	i;

	i = 0;
	while (i < dict_size)
	{
		if (ft_strcmp(dict[i].key, key_str) == 0)
		{
			return (dict[i].value);
		}
		i++;
	}
	return (NULL);
}
