/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktei <ktei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:51:49 by ktei              #+#    #+#             */
/*   Updated: 2024/09/22 22:21:49 by ktei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

void	output_origin(char *dict, int argc, char *argv[])
{
	char	*input;
	int		digits;

	input = argv[argc - 1];
	digits = ft_len_nbr(input);
	if (digits <= 3)
		output_small(dict, digits, input);
	else
	{
		output_large(dict, input);
	}
}

void	output_small_2(int digits, char *input, char *dict, int k)
{
	if (digits == 2 && input[1] == '0' && input[2] == '0')
		return ;
	if (digits == 2 && input[k] == '1')
	{
		output_teens(dict, input, k);
		return ;
	}
	if (digits == 2 && input[k] != '0')
		point_to_nbr(input[k], 2, dict, (input[k + 1] == '0'));
	if (digits == 2)
	{
		digits--;
		k++;
	}
	if (digits == 1)
		point_to_nbr(input[k], 1, dict, 1);
}

void	output_small(char *dict, int digits, char *input)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	if ((digits == 1 && input[0] == '0') || (digits == 2 && input[0] == '0'
			&& input[1] == '0') || (digits == 3 && input[0] == '0'
			&& input[1] == '0' && input[2] == '0'))
	{
		point_zero(dict);
		return ;
	}
	if (digits == 3)
	{
		if (input[0] != '0')
		{
			point_to_nbr(input[0], 1, dict, 0);
			point_to_nbr('1', 3, dict, ((input[1] == '0')
					&& (input[2] == '0')));
		}
		digits--;
		k++;
	}
	output_small_2(digits, input, dict, k);
}

int	point_zero(char *dict)
{
	char	*found;

	found = consult_dict(dict, "0");
	if (!found)
	{
		return (1);
	}
	put_words(found, 1);
	return (0);
}
