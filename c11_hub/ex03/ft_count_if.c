/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:41:45 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/19 11:33:01 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_count_if(char **tab, int length, int (*f)(char *))
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < length && tab[i] != NULL)
	{
		if ((*f)(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

// #include <stdio.h>

// // Function to check if the string is non-empty
// int	is_non_empty(char *str)
// {
// 	return (str[0] != '\0');
// }

// // Main function
// int	main(void)
// {
// 	int		result;
// 	char	*tab[] = {"", "hello", "world", "aa", "42", "fasd", "", NULL};
// 	int		length;

// 	// Array of strings
// 	length = 5;
// 	// Array length
// 	// Test ft_count_if with the is_non_empty function
// 	result = ft_count_if(tab, length, &is_non_empty);
// 	printf("Number of non-empty strings: %d\n", result);
// 	return (0);
// }
