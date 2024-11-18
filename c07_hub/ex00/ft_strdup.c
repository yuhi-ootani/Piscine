/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 20:37:36 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/18 13:34:50 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_strlen(char *src)
{
	int	len;

	len = 0;
	while (src[len])
	{
		len++;
	}
	return (len);
}

void	ft_strcpy(char *dest, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*copy;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	ft_strcpy(copy, src);
	return (copy);
}

int	main(void)
{
	// Test Case 1: Simple String Duplication
	char *src1 = "Hello, World!";
	char *dup1 = ft_strdup(src1);
	printf("Test Case 1: Simple String Duplication\n");
	printf("Original: %s\n", src1);
	printf("Duplicated: %s\n", dup1);
	free(dup1); // Remember to free the memory allocated by ft_strdup

	// Test Case 2: Empty String Duplication
	char *src2 = "";
	char *dup2 = ft_strdup(src2);
	printf("\nTest Case 2: Empty String Duplication\n");
	printf("Original: '%s'\n", src2);
	printf("Duplicated: '%s'\n", dup2);
	free(dup2); // Free the memory

	// Test Case 3: Long String Duplication
	char *src3 = "This is a longer string for testing ft_strdup function!";
	char *dup3 = ft_strdup(src3);
	printf("\nTest Case 3: Long String Duplication\n");
	printf("Original: %s\n", src3);
	printf("Duplicated: %s\n", dup3);
	free(dup3); // Free the memory

	// Test Case 4: Null Pointer (Optional case, depends on your implementation)
	char *dup4 = ft_strdup(NULL);
	printf("\nTest Case 4: Null Pointer\n");
	if (dup4 == NULL)
	{
		printf("Duplicated: NULL (Handled correctly)\n");
	}
	else
	{
		printf("Duplicated: %s (Check your handling for NULL input)\n", dup4);
		free(dup4); // Free if not NULL
	}

	return (0);
}