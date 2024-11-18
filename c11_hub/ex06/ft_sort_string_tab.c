/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 09:57:50 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/23 09:47:50 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *a, char *b)
{
	while (*a == *b && *a && *b)
	{
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}

void	ft_swap_str(char **a, char **b)
{
	char	*temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

void	ft_sort_string_tab(char **tab)
{
	int	i;
	int	j;
	int	size;

	if (!tab)
		return ;
	size = 0;
	while (tab[size])
		size++;
	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - 1 - i)
		{
			if (ft_strcmp(tab[j], tab[j + 1]) > 0)
			{
				ft_swap_str(&tab[j], &tab[j + 1]);
			}
			j++;
		}
		i++;
	}
}

// #include <stdio.h>

// void	print_tab(char **tab)
// {
// 	for (int i = 0; tab[i] != NULL; i++)
// 	{
// 		printf("%s\n", tab[i]);
// 	}
// }

// int	main(void)
// {
// 	char	*tab1[] = {"banana", "apple", "orange", "grape", NULL};
// 	char	*tab2[] = {"apple", "orange", "banana", "apple", NULL};
// 	char	*tab3[] = {"Banana", "apple", "Orange", "grape", NULL};
// 	char	*tab4[] = {NULL};
// 	char	*tab5[] = {"single", NULL};

// 	// Test Case 1: Basic string sorting
// 	printf("Test Case 1: Before sorting:\n");
// 	print_tab(tab1);
// 	ft_sort_string_tab(tab1);
// 	printf("Test Case 1: After sorting:\n");
// 	print_tab(tab1);
// 	printf("\n");
// 	// Test Case 2: Sorting with duplicate strings
// 	printf("Test Case 2: Before sorting:\n");
// 	print_tab(tab2);
// 	ft_sort_string_tab(tab2);
// 	printf("Test Case 2: After sorting:\n");
// 	print_tab(tab2);
// 	printf("\n");
// 	// Test Case 3: Strings with uppercase and lowercase letters
// 	printf("Test Case 3: Before sorting:\n");
// 	print_tab(tab3);
// 	ft_sort_string_tab(tab3);
// 	printf("Test Case 3: After sorting:\n");
// 	print_tab(tab3);
// 	printf("\n");
// 	// Test Case 4: Empty array
// 	printf("Test Case 4: Before sorting:\n");
// 	print_tab(tab4);
// 	ft_sort_string_tab(tab4);
// 	printf("Test Case 4: After sorting:\n");
// 	print_tab(tab4);
// 	printf("\n");
// 	// Test Case 5: Array with only one element
// 	printf("Test Case 5: Before sorting:\n");
// 	print_tab(tab5);
// 	ft_sort_string_tab(tab5);
// 	printf("Test Case 5: After sorting:\n");
// 	print_tab(tab5);
// 	printf("\n");
// 	return (0);
// }
