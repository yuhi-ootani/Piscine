/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 19:35:51 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/07 11:13:52 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print(int *arr, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = arr[i] + '0';
		write(1, &c, 1);
		i++;
	}
	if (arr[0] != 10 - n)
	{
		write(1, ", ", 2);
	}
}

void	ft_recursive_combn(int *arr, int n, int idx, int pre)
{
	int	digit;

	if (idx == n)
	{
		ft_print(arr, n);
		return ;
	}
	digit = pre + 1;
	while (digit <= 9)
	{
		arr[idx] = digit;
		ft_recursive_combn(arr, n, idx + 1, digit);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	int	arr[10];

	if (n > 0 && n < 10)
	{
		ft_recursive_combn(arr, n, 0, -1);
	}
}

// int	main(void)
// {
// 	ft_print_combn(3);
// 	return (0);
// }