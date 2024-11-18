/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4split_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/22 19:33:47 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/22 20:15:54 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

void	process_group(char *buffer, int grp_cnt, t_dict_entry *dict, int d_size)
{
	if (ft_atoi(buffer) != 0)
	{
		convert_below_1000(ft_atoi(buffer), dict, d_size);
		if (grp_cnt > 1)
			append_unit_and_space(grp_cnt, dict, d_size);
	}
}

void	process_number_groups(char *padded_nbr, int grp_cnt, t_dict_entry *dict,
		int d_size)
{
	int		start;
	char	buffer[4];
	int		first_non_zero_group;

	start = 0;
	first_non_zero_group = 1;
	while (start < ft_strlen(padded_nbr))
	{
		ft_strncpy(buffer, &padded_nbr[start], 3);
		buffer[3] = '\0';
		if (ft_atoi(buffer) != 0)
		{
			if (!first_non_zero_group)
				ft_putchar(' ');
			else
				first_non_zero_group = 0;
			process_group(buffer, grp_cnt, dict, d_size);
		}
		start += 3;
		grp_cnt--;
	}
}

char	*pad_number(char *nbr)
{
	int		len;
	int		pad_len;
	char	*padded_nbr;

	len = ft_strlen(nbr);
	pad_len = (3 - (len % 3)) % 3;
	padded_nbr = malloc(len + pad_len + 1);
	if (!padded_nbr)
		return (NULL);
	ft_memset(padded_nbr, '0', pad_len);
	ft_strcpy(&padded_nbr[pad_len], nbr);
	padded_nbr[len + pad_len] = '\0';
	return (padded_nbr);
}

// if (!check_large_number(nbr, dict, d_size))
// 	return ;
void	process_large_number(char *nbr, t_dict_entry *dict, int d_size)
{
	int		len;
	int		grp_cnt;
	char	*padded_nbr;

	padded_nbr = pad_number(nbr);
	if (!padded_nbr)
		return ;
	len = ft_strlen(padded_nbr);
	grp_cnt = (len + 2) / 3;
	process_number_groups(padded_nbr, grp_cnt, dict, d_size);
	ft_putchar('\n');
	free(padded_nbr);
}
