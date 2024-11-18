/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 21:51:16 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/16 10:27:19 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	ft_strcpy(char *dest, int size, char **strs, char *sep)
{
	int	i;
	int	j;
	int	dest_i;

	i = 0;
	dest_i = 0;
	while (i < size)
	{
		j = 0;
		while (strs[i][j])
			dest[dest_i++] = strs[i][j++];
		if (i != (size - 1))
		{
			j = 0;
			while (sep[j])
				dest[dest_i++] = sep[j++];
		}
		i++;
	}
	dest[dest_i] = '\0';
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*result;
	int		total_len;
	int		i;

	if (size <= 0)
	{
		result = (char *)malloc(sizeof(char) * 1);
		if (result == NULL)
			return (NULL);
		result[0] = '\0';
		return (result);
	}
	if (sep == NULL)
		sep = "";
	total_len = ft_strlen(sep);
	total_len *= (size - 1);
	i = 0;
	while (i < size)
		total_len += ft_strlen(strs[i++]);
	result = (char *)malloc(sizeof(char) * (total_len + 1));
	if (result == NULL)
		return (NULL);
	ft_strcpy(result, size, strs, sep);
	return (result);
}

// int	main(void)
// {
// 	char *strs[] = {"Hello", "World", "42"};
// 	char *sep = " ";
// 	char *result;

// 	// Test case 1: Normal case with 3 strings
// 	result = ft_strjoin(3, strs, sep);
// 	printf("Result 1: %s\n", result);
// 	free(result);

// 	// Test case 2: Only 1 string
// 	result = ft_strjoin(1, strs, sep);
// 	printf("Result 2: %s\n", result);
// 	free(result);

// 	// Test case 3: No strings, size = 0
// 	result = ft_strjoin(0, strs, sep);
// 	printf("Result 3: '%s'\n", result); // Should print an empty string
// 	free(result);

// 	// Test case 4: Empty strings
// 	char *empty_strs[] = {"", "", ""};
// 	result = ft_strjoin(3, empty_strs, sep);
// 	printf("Result 4: '%s'\n", result);
// 	free(result);

// 	// Test case 5: Custom separator
// 	char *custom_sep = "---";
// 	result = ft_strjoin(3, strs, custom_sep);
// 	printf("Result 5: %s\n", result);
// 	free(result);

// 	return (0);
// }