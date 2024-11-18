/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 11:35:37 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/13 19:42:38 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_iterative_factorial(int nb)
{
	int	factorial;

	factorial = 1;
	if (nb < 0)
		return (0);
	while (nb > 0)
	{
		factorial = factorial * nb;
		nb--;
	}
	return (factorial);
}

// int	main(void)
// {
// 	printf("Factorial of -5: %d\n", ft_iterative_factorial(-5)); // 無効なので 0 を返す
// 	printf("Factorial of 0: %d\n", ft_iterative_factorial(0));   // 0! = 1
// 	printf("Factorial of 1: %d\n", ft_iterative_factorial(1));   // 1! = 1
// 	printf("Factorial of 5: %d\n", ft_iterative_factorial(5));   // 5! = 120
// 	printf("Factorial of 10: %d\n", ft_iterative_factorial(10));
// 	// 10! = 3628800
// 	return (0);
// }