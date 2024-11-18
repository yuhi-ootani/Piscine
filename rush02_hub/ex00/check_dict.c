/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktei <ktei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 15:05:28 by ktei              #+#    #+#             */
/*   Updated: 2024/09/22 23:24:46 by ktei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

void	check_dict2(char *dict, int *i, int *flag)
{
	while (dict[*i] == ' ')
		(*i)++;
	if (dict[*i] == ':')
	{
		(*flag)++;
		(*i)++;
	}
	while (dict[*i] == ' ')
		(*i)++;
	while (((dict[*i] == ' ') || (dict[*i] >= 33 && dict[*i] <= 126))
		&& *flag >= 2)
	{
		(*flag)++;
		(*i)++;
	}
	if (dict[*i] == '\n')
	{
		(*flag)++;
		(*i)++;
	}
}

int	check_dict(char *dict)
{
	int	i;
	int	flag;

	i = 0;
	while (dict[i])
	{
		flag = 0;
		while (dict[i] == ' ' || (dict[i] >= 9 && dict[i] <= 13)
			|| dict[i] == '\n')
			i++;
		if (dict[i] == '+' || dict[i] == '-')
			i++;
		while (dict[i] <= '9' && dict[i] >= '0')
		{
			flag++;
			i++;
		}
		check_dict2(dict, &i, &flag);
		if (flag < 4)
			return (-1);
	}
	return (1);
}

int	check_digits(int argc, char *argv[])
{
	int	i;

	i = ft_len_nbr(argv[argc - 1]);
	if (i >= 40)
		return (-1);
	return (0);
}
