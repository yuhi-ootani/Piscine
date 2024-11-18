/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktei <ktei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 17:00:42 by ktei              #+#    #+#             */
/*   Updated: 2024/09/22 21:45:15 by ktei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

void	devided_by_three(char *buffer, int start, char *dict)
{
	char	head[4];

	ft_strncpy(head, &buffer[start], (unsigned int)3);
	head[3] = '\0';
	if (ft_atoi_p(head) != 0)
		output_small(dict, 3, head);
}

void	add_unit_2(char *found, char *cand)
{
	if (!found)
	{
		write(1, "Dict Error", 10);
		free(cand);
		return ;
	}
	if (found)
		write(1, " ", 1);
	put_words(found, 0);
	free(cand);
}

int	add_unit(int len, char *dict, int start, char *buffer)
{
	char	*cand;
	int		i;
	char	*found;

	if (buffer[start] == '0' && buffer[start + 1] == '0'
		&& buffer[start + 2] == '0')
		return (0);
	cand = (char *)malloc(sizeof(char) * (len + 1));
	if (!cand)
		return (1);
	cand[0] = '1';
	i = 1;
	while (i <= len - start - 3)
	{
		cand[i] = '0';
		i++;
	}
	cand[i] = '\0';
	found = consult_dict(dict, cand);
	add_unit_2(found, cand);
	return (0);
}

void	output_large_2(int len, char *buffer, char *dict)
{
	int	i;

	i = 0;
	while (i < len)
	{
		devided_by_three(buffer, i, dict);
		if (i < len - 3)
			add_unit(len, dict, i, buffer);
		i += 3;
	}
}

void	output_large(char *dict, char *input)
{
	int		len;
	int		padding;
	char	*buffer;
	int		i;

	len = ft_len_nbr(input);
	padding = (3 - len % 3) % 3;
	buffer = (char *)malloc(sizeof(char) * (len + padding + 1));
	if (!buffer)
	{
		write(1, "Error\n", 6);
		return ;
	}
	i = 0;
	while (i < padding)
		buffer[i++] = '0';
	ft_strcpy(&buffer[padding], input);
	len += padding;
	buffer[len] = '\0';
	output_large_2(len, buffer, dict);
	free(buffer);
}
