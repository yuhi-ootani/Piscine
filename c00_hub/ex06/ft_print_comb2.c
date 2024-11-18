/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 16:35:12 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/06 20:42:03 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_write(int i, int j)
{
	char	c[5];

	c[0] = '0' + i / 10;
	c[1] = '0' + i % 10;
	c[2] = ' ';
	c[3] = '0' + j / 10;
	c[4] = '0' + j % 10;
	write(1, &c, 5);
	if (i != 98 || j != 99)
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb2(void)
{
	int	i;
	int	j;

	i = 0;
	while (i <= 98)
	{
		j = i + 1;
		while (j <= 99)
		{
			ft_write(i, j);
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_comb2();
// 	return (0);
// }