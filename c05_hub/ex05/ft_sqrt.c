/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/11 20:39:49 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/13 19:39:03 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	int		start;
	int		end;
	int		m;
	long	multiplied;

	if (nb <= 0)
		return (0);
	start = 1;
	end = nb;
	while (start <= end)
	{
		m = (start + end) / 2;
		multiplied = (long)m * m;
		if (multiplied == nb)
			return (m);
		else if (multiplied < nb)
			start = m + 1;
		else
			end = m - 1;
	}
	return (0);
}

// int	main(void)
// {
// 	int numbers[] = {16, 25, 0, -4, 10, 144, 81, 2147483647, -2147483648};
// 	int size = sizeof(numbers) / sizeof(numbers[0]);

// 	for (int i = 0; i < size; i++)
// 	{
// 		int result = ft_sqrt(numbers[i]);
// 		if (result == 0)
// 			printf("The number %d does not have a natural square root.\n",
// 				numbers[i]);
// 		else
// 			printf("The natural square root of %d is %d.\n", numbers[i],
// 				result);
// 	}

// 	return (0);
// }