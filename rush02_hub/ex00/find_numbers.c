/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_numbers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktei <ktei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 19:11:37 by ktei              #+#    #+#             */
/*   Updated: 2024/09/22 21:33:09 by ktei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

char	*consult_dict_2(int *i, char *str, char *to_find)
{
	int	k;

	while (str[*i] != ':' && str[*i] != '\0')
	{
		k = 0;
		while (to_find[k] != '\0' && str[*i + k] == to_find[k])
			k++;
		if (to_find[k] == '\0' && (str[*i + k] == ':' || str[*i + k] == ' '))
		{
			(*i) += k;
			while (str[*i] != ':' && str[*i] != '\0')
				(*i)++;
			if (str[*i] == ':')
				(*i)++;
			while (str[*i] == ' ' || (str[*i] >= 9 && str[*i] <= 13))
				(*i)++;
			return (&str[*i]);
		}
		while (str[*i] != '\n' && str[*i] != '\0')
			(*i)++;
		if (str[*i] != '\0')
			(*i)++;
	}
	return (NULL);
}

char	*consult_dict(char *str, char *to_find)
{
	int		i;
	char	*dest;

	i = 0;
	while (str[i] != '\0')
	{
		dest = consult_dict_2(&i, str, to_find);
		if (dest)
			return (dest);
	}
	return (NULL);
}

void	put_words(char *found, int flag)
{
	int	margin;

	margin = 0;
	while (*found != '\n' && *found != '\0')
	{
		while (*found == ' ' && margin == 0)
			found++;
		margin = 1;
		if (*found >= 32 && *found <= 126)
			write(1, found, 1);
		found++;
	}
	if (flag == 0)
		write(1, " ", 1);
}

int	point_to_nbr(char input, int digits, char *dict, int flag)
{
	char	*dest;
	int		i;
	char	*found;

	dest = (char *)malloc(sizeof(char) * (digits + 1));
	if (!dest)
		return (1);
	dest[0] = input;
	i = 1;
	while (i < digits)
		dest[i++] = '0';
	dest[i] = '\0';
	found = consult_dict(dict, dest);
	if (!found)
	{
		free(dest);
		return (1);
	}
	if (input != '0')
		put_words(found, flag);
	free(dest);
	return (0);
}
