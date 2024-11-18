/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:01:33 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/13 19:38:29 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>

int	ft_is_prime(int nb)
{
	int	base;

	if (nb <= 1)
		return (0);
	if (nb == 2)
		return (1);
	if (nb % 2 == 0 && nb != 2)
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

int	ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	if (nb % 2 == 0)
		nb++;
	while (!ft_is_prime(nb))
		nb += 2;
	return (nb);
}

// int	main(void)
// {
// 	// テストケース 1: 2以下の入力
// 	printf("Next prime after -10: %d\n", ft_find_next_prime(-10)); // 2
// 	printf("Next prime after 0: %d\n", ft_find_next_prime(0));     // 2
// 	printf("Next prime after 1: %d\n", ft_find_next_prime(1));     // 2
// 	printf("Next prime after 2: %d\n", ft_find_next_prime(2));     // 2

// 	// テストケース 2: 素数でない数
// 	printf("Next prime after 4: %d\n", ft_find_next_prime(4));     // 5
// 	printf("Next prime after 10: %d\n", ft_find_next_prime(10));   // 11
// 	printf("Next prime after 100: %d\n", ft_find_next_prime(100)); // 101

// 	// テストケース 3: 素数の入力
// 	printf("Next prime after 3: %d\n", ft_find_next_prime(3));   // 3
// 	printf("Next prime after 17: %d\n", ft_find_next_prime(17)); // 17

// 	// テストケース 4: INT_MAX のテスト
// 	printf("Next prime after INT_MAX: %d\n", ft_find_next_prime(INT_MAX));
// 	// 大きな素数が返される

// 	// テストケース 5: INT_MAX - 1 のテスト
// 	printf("Next prime after INT_MAX - 1: %d\n", ft_find_next_prime(INT_MAX
// 			- 1)); // INT_MAXの次の素数が返される

// 	return (0);
// }