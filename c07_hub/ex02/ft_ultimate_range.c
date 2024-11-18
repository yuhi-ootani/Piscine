/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:37:45 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/16 10:29:43 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	diff;
	int	*array;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	diff = max - min;
	array = (int *)malloc(sizeof(int) * diff);
	if (array == NULL)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		array[i] = min + i;
		i++;
	}
	*range = array;
	return (diff);
}

// int	main(void)
// {
// 	int *range;
// 	int size;
// 	int i;

// 	// 通常ケース: min = 3, max = 10
// 	size = ft_ultimate_range(&range, 3, 10);
// 	if (size == -1)
// 	{
// 		printf("Error: memory allocation failed\n");
// 	}
// 	else if (size == 0)
// 	{
// 		printf("Empty range or invalid input\n");
// 	}
// 	else
// 	{
// 		printf("Range size: %d\n", size);
// 		for (i = 0; i < size; i++)
// 		{
// 			printf("%d ", range[i]);
// 		}
// 		printf("\n");
// 	}
// 	free(range);

// 	// エッジケース: min = 5, max = 5 (無効な範囲)
// 	size = ft_ultimate_range(&range, 5, 5);
// 	if (size == 0)
// 	{
// 		printf("Empty range or invalid input\n");
// 	}
// 	free(range);

// 	// 通常ケース: min = -5, max = 0
// 	size = ft_ultimate_range(&range, -5, 0);
// 	if (size == -1)
// 	{
// 		printf("Error: memory allocation failed\n");
// 	}
// 	else
// 	{
// 		printf("Range size: %d\n", size);
// 		for (i = 0; i < size; i++)
// 		{
// 			printf("%d ", range[i]);
// 		}
// 		printf("\n");
// 	}
// 	free(range);

// 	return (0);
// }