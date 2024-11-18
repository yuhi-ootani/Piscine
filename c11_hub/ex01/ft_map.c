/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:22:19 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/19 11:34:11 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*result;

	i = 0;
	result = (int *)malloc(sizeof(int) * (length));
	if (!result)
		return (NULL);
	while (i < length)
	{
		result[i] = (*f)(tab[i]);
		i++;
	}
	return (result);
}

// #include <stdio.h>
// #include <stdlib.h>

// // Function that doubles the value
// int	double_value(int n)
// {
// 	return (n * 2);
// }

// // Main function
// int	main(void)
// {
// 	int	i;

// 	int tab[] = {1, 2, 3, 4, 5}; // Original array
// 	int length = 5;              // Array length
// 	int *result;                 // Pointer to store the result
// 	// Using ft_map to apply double_value to each element
// 	result = ft_map(tab, length, &double_value);
// 	// Print the result array
// 	for (i = 0; i < length; i++)
// 	{
// 		printf("%d ", result[i]);
// 	}
// 	printf("\n");
// 	// Free the allocated memory
// 	free(result);
// 	return (0);
// }
