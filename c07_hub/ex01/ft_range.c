/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:26:29 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/16 10:30:45 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	*ft_range(int min, int max)
{
	int	diff;
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	diff = max - min;
	range = (int *)malloc(sizeof(int) * diff);
	if (range == NULL)
		return (NULL);
	i = 0;
	while (min + i < max)
	{
		range[i] = min + i;
		i++;
	}
	return (range);
}

// int	main(void)
// {
// 	int *arr;
// 	int i;

// 	// Test case 1: min = 5, max = 10
// 	arr = ft_range(5, 10);
// 	if (arr == NULL)
// 		printf("NULL\n");
// 	else
// 	{
// 		for (i = 0; i < 10 - 5; i++)
// 			printf("%d ", arr[i]);
// 		printf("\n");
// 		free(arr);
// 	}

// 	// Test case 2: min = 0, max = 1
// 	arr = ft_range(0, 1);
// 	if (arr == NULL)
// 		printf("NULL\n");
// 	else
// 	{
// 		for (i = 0; i < 1 - 0; i++)
// 			printf("%d ", arr[i]);
// 		printf("\n");
// 		free(arr);
// 	}

// 	// Test case 3: min = -5, max = 0
// 	arr = ft_range(-5, 0);
// 	if (arr == NULL)
// 		printf("NULL\n");
// 	else
// 	{
// 		for (i = 0; i < 0 + 5; i++)
// 			printf("%d ", arr[i]);
// 		printf("\n");
// 		free(arr);
// 	}

// 	// Test case 4: min = 3, max = 3 (NULL case)
// 	arr = ft_range(3, 3);
// 	if (arr == NULL)
// 		printf("NULL\n");

// 	// Test case 5: min = 10, max = 5 (NULL case)
// 	arr = ft_range(10, 5);
// 	if (arr == NULL)
// 		printf("NULL\n");

// 	return (0);
// }