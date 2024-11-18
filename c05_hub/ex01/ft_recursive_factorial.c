/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 13:17:35 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/13 19:42:22 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_recursive_factorial(int nb)
{
	if (nb < 0)
		return (0);
	if (nb == 0)
		return (1);
	return (nb * ft_recursive_factorial(nb - 1));
}

// int	main(void)
// {
// 	// 通常の正の整数
// 	printf("5! = %d\n", ft_recursive_factorial(5)); // 120
// 	printf("3! = %d\n", ft_recursive_factorial(3)); // 6

// 	// 0 のケース
// 	printf("0! = %d\n", ft_recursive_factorial(0)); // 1

// 	// 負の数
// 	printf("-3! = %d\n", ft_recursive_factorial(-3)); // 0

// 	// 大きな数 (オーバーフローは処理しないが、試しに確認)
// 	printf("12! = %d\n", ft_recursive_factorial(12)); // 479001600

// 	return (0);
// }