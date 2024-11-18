/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 11:06:37 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 08:13:39 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	is_ascending;
	int	is_descending;

	i = 0;
	is_ascending = 1;
	is_descending = 1;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			is_ascending = 0;
		if ((*f)(tab[i], tab[i + 1]) < 0)
			is_descending = 0;
		i++;
	}
	return (is_ascending || is_descending);
}

// #include <stdio.h>

// int	ascending(int a, int b)
// {
// 	return (a - b);
// }

// int	descending(int a, int b)
// {
// 	return (b - a);
// }

// int	main(void)
// {
// 	int	tab1[] = {1, 2, 3, 4, 55};
// 	int	tab2[] = {5, 1, 3, 4, 2};
// 	int	tab3[] = {5, 4, 3, 2, 1};
// 	int	tab4[] = {7, 7, 7, 7, 7};
// 	int	tab5[] = {42};
// 	int	tab6[] = {};
// 	int	tab7[] = {1, 2, 3, 5, 4};

// 	// Test Case 1: Sorted in ascending order
// 	printf("Test Case 1: %d\n", ft_is_sort(tab1, 5, ascending));
// 	// Expected: 1 (True)
// 	// Test Case 2: Not sorted
// 	printf("Test Case 2: %d\n", ft_is_sort(tab2, 5, ascending));
// 	// Expected: 0 (False)
// 	// Test Case 3: Sorted in descending order
// 	printf("Test Case 3: %d\n", ft_is_sort(tab3, 5, descending));
// 	// Expected: 1 (True)
// 	// Test Case 4: All elements are the same
// 	printf("Test Case 4: %d\n", ft_is_sort(tab4, 5, ascending));
// 	// Expected: 1 (True)
// 	// Test Case 5: Only one element
// 	printf("Test Case 5: %d\n", ft_is_sort(tab5, 1, ascending));
// 	// Expected: 1 (True)
// 	// Test Case 6: Empty array (length 0)
// 	printf("Test Case 6: %d\n", ft_is_sort(tab6, 0, ascending));
// 	// Expected: 1 (True)
// 	// Test Case 7: Partially sorted array
// 	printf("Test Case 7: %d\n", ft_is_sort(tab7, 5, ascending));
// 	// Expected: 0 (False)
// 	return (0);
// }
