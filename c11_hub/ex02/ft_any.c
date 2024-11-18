/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:35:25 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/19 11:33:28 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
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
// 	int	result;

// 	char *tab[] = {"", "", "a", NULL}; // Array of strings
// 	// Test ft_any with the is_non_empty function
// 	result = ft_any(tab, &is_non_empty);
// 	if (result == 1)
// 		printf("At least one non-empty string found.\n");
// 	else
// 		printf("All strings are empty.\n");
// 	return (0);
// }
