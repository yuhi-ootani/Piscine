/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 19:51:55 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/16 15:12:20 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_power(int nb, int power)
{
	if (power == 0)
		return (1);
	if (power < 0 || nb == 0)
		return (0);
	return (nb * ft_recursive_power(nb, power - 1));
}

int	main(void)
{
	// テストケース1: 2の4乗
	printf("2^4 = %d\n", ft_recursive_power(2, 4)); // 16

	// テストケース2: 0の0乗
	printf("0^0 = %d\n", ft_recursive_power(0, 0)); // 1

	// テストケース3: 5の3乗
	printf("5^3 = %d\n", ft_recursive_power(5, 3)); // 125

	// テストケース4: 10の1乗
	printf("10^1 = %d\n", ft_recursive_power(10, 1)); // 10

	// テストケース5: 0の5乗
	printf("0^5 = %d\n", ft_recursive_power(0, 5)); // 0

	// テストケース6: 負のべき乗 (無効なケース)
	printf("2^-3 = %d\n", ft_recursive_power(2, -3)); // 0

	// テストケース7:  0の0乗
	printf("0^0 = %d\n", ft_recursive_power(0, 0)); // 1

	// テストケース8:  5の0乗
	printf("5^0 = %d\n", ft_recursive_power(5, 0)); // 1

	// テストケース9:  5の0乗
	printf("-3^3 = %d\n", ft_recursive_power(-3, 3)); // 1
	return (0);
}