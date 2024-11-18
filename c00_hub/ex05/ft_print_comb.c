/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 15:20:27 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/06 20:41:56 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	add_space(int i, int j, int k)
{
	if (i != 7 || j != 8 || k != 9)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	while (i <= 7)
	{
		j = i + 1;
		while (j <= 8)
		{
			k = j + 1;
			while (k <= 9)
			{
				write(1, &"0123456789"[i], 1);
				write(1, &"0123456789"[j], 1);
				write(1, &"0123456789"[k], 1);
				add_space(i, j, k);
				k++;
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_comb();
// 	return (0);
// }
