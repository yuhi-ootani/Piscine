/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 21:20:29 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/13 19:38:41 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	base;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0)
		return (0);
	base = 3;
	while (base <= nb / base)
	{
		if (nb % base == 0)
			return (0);
		base += 2;
	}
	return (1);
}

// int	main(void)
// {
// 	// 素数でない場合
// 	printf("Test with 0: %d (Expected: 0)\n", ft_is_prime(0));     // 0は素数ではない
// 	printf("Test with 1: %d (Expected: 0)\n", ft_is_prime(1));     // 1は素数ではない
// 	printf("Test with 4: %d (Expected: 0)\n", ft_is_prime(4));     // 4は素数ではない
// 	printf("Test with 9: %d (Expected: 0)\n", ft_is_prime(9));     // 9は素数ではない
// 	printf("Test with 100: %d (Expected: 0)\n", ft_is_prime(100)); // 100は素数ではない
// 	printf("2147483646: %d\n", ft_is_prime(2147483646));           // 非素数

// 	// 素数の場合
// 	printf("Test with 2: %d (Expected: 1)\n", ft_is_prime(2));   // 2は素数
// 	printf("Test with 3: %d (Expected: 1)\n", ft_is_prime(3));   // 3は素数
// 	printf("Test with 5: %d (Expected: 1)\n", ft_is_prime(5));   // 5は素数
// 	printf("Test with 7: %d (Expected: 1)\n", ft_is_prime(7));   // 7は素数
// 	printf("Test with 11: %d (Expected: 1)\n", ft_is_prime(11)); // 11は素数
// 	printf("Test with 13: %d (Expected: 1)\n", ft_is_prime(13)); // 13は素数
// 	printf("Test with 97: %d (Expected: 1)\n", ft_is_prime(97)); // 97は素数
// 	printf("2147483647: %d\n", ft_is_prime(2147483647));
// 	return (0);
// }