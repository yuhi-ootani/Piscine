/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6convert_hundreds.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:33:47 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/22 19:50:49 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

void	append_unit_and_space(int grp_cnt, t_dict_entry *dict, int d_size)
{
	char		unit_key[40];
	int			i;
	const char	*unit;

	ft_strcpy(unit_key, "1");
	i = 0;
	while (i < (grp_cnt - 1) * 3)
	{
		unit_key[i + 1] = '0';
		unit_key[i + 2] = '\0';
		i++;
	}
	unit = find_unit_by_string(unit_key, dict, d_size);
	if (unit)
	{
		ft_putchar(' ');
		ft_putstr(unit);
	}
}

void	convert_below_1000(unsigned long long num, t_dict_entry *dict,
		int dict_size)
{
	if (num == 0)
		return ;
	if (num < 20)
		ft_putstr(find_word(num, dict, dict_size));
	else if (num < 100)
	{
		ft_putstr(find_word((num / 10) * 10, dict, dict_size));
		if (num % 10)
		{
			ft_putchar(' ');
			ft_putstr(find_word(num % 10, dict, dict_size));
		}
	}
	else
	{
		ft_putstr(find_word(num / 100, dict, dict_size));
		ft_putchar(' ');
		ft_putstr(find_word(100, dict, dict_size));
		if (num % 100)
		{
			ft_putchar(' ');
			convert_below_1000(num % 100, dict, dict_size);
		}
	}
}
