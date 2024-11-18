/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:44:33 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/13 19:42:13 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_power(int nb, int power)
{
	int	result;

	result = 1;
	if (power < 0)
		return (0);
	if (nb == 0 && power == 0)
		return (1);
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

// int	main(void)
// {
// 	// テストケース1: 2の4乗
// 	printf("2^4 = %d\n", ft_iterative_power(2, 4)); // 16

// 	// テストケース2: 0の0乗
// 	printf("0^0 = %d\n", ft_iterative_power(0, 0)); // 1

// 	// テストケース3: 5の3乗
// 	printf("5^3 = %d\n", ft_iterative_power(5, 3)); // 125

// 	// テストケース4: 10の1乗
// 	printf("10^1 = %d\n", ft_iterative_power(10, 1)); // 10

// 	// テストケース5: 0の5乗
// 	printf("0^5 = %d\n", ft_iterative_power(0, 5)); // 0

// 	// テストケース6: 負のべき乗 (無効なケース)
// 	printf("2^-3 = %d\n", ft_iterative_power(2, -3)); // 0
// 	return (0);
// }