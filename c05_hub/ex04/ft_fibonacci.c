/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:24:40 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/21 21:58:44 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_fibonacci(int index)
{
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (0);
	else if (index == 1)
		return (1);
	return (ft_fibonacci(index - 1) + ft_fibonacci(index - 2));
}

int	main(void)
{
	// テストケース
	printf("Fibonacci(0) = %d\n", ft_fibonacci(0)); // 期待値: 0
	printf("Fibonacci(1) = %d\n", ft_fibonacci(1)); // 期待値: 1
	printf("Fibonacci(2) = %d\n", ft_fibonacci(2)); // 期待値: 1
	printf("Fibonacci(3) = %d\n", ft_fibonacci(3)); // 期待値: 2
	printf("Fibonacci(4) = %d\n", ft_fibonacci(4)); // 期待値: 3
	printf("Fibonacci(5) = %d\n", ft_fibonacci(5)); // 期待値: 5
	printf("Fibonacci(6) = %d\n", ft_fibonacci(6)); // 期待値: 8
	printf("Fibonacci(7) = %d\n", ft_fibonacci(7)); // 期待値: 13

	// 境界ケース
	printf("Fibonacci(-1) = %d\n", ft_fibonacci(-1)); // 期待値: -1 (負の数の処理)
	printf("Fibonacci(10) = %d\n", ft_fibonacci(10)); // 期待値: 55
	return (0);
}