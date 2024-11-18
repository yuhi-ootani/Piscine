/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teens.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktei <ktei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 21:26:58 by ktei              #+#    #+#             */
/*   Updated: 2024/09/22 22:10:39 by ktei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

char	*search_teams_2(char *dict, char *input, int *i)
{
	int	k;

	k = 0;
	while (dict[*i] == input[k] && input[k] != '\0' && dict[*i] != ':')
	{
		(*i)++;
		k++;
	}
	if ((input[k] == '\0') && (dict[*i] == ':' || dict[*i] == ' '))
	{
		while (dict[*i] != ':' && dict[*i] != '\0')
			(*i)++;
		if (dict[*i] == ':')
			(*i)++;
		while (dict[*i] == ' ' || (dict[*i] >= 9 && dict[*i] <= 13))
			(*i)++;
		return (&dict[*i]);
	}
	while (dict[*i] != '\n' && dict[*i] != '\0')
		(*i)++;
	return (NULL);
}

char	*search_teens(char *dict, char *input)
{
	int		i;
	char	*dest;

	i = 0;
	while (dict[i])
	{
		dest = search_teams_2(dict, input, &i);
		if (dest)
			return (dest);
		if (dict[i] == '\0')
			break ;
		i++;
	}
	return (NULL);
}

int	output_teens(char *dict, char *input, int k)
{
	char	*dest;
	char	*found;

	dest = (char *)malloc(sizeof(char) * (2 + 1));
	if (!dest)
		return (1);
	if (k > 0)
		input += k;
	found = search_teens(dict, input);
	if (!found)
	{
		free(dest);
		return (1);
	}
	put_words(found, 1);
	free(dest);
	return (0);
}
