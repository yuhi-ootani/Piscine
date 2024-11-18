/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:44:18 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/10 09:58:57 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	if (i < n)
	{
		return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	}
	return (0);
}

// int	main(void)
// {
// 	static char str0[] = "apple";
// 	static char str1[] = "apple";
// 	static char str2[] = "applf";
// 	static char str3[] = "appl";

// 	int a;

// 	a = ft_strncmp(str0, str2, 4);
// 	printf("%d\n", a);
// 	a = ft_strncmp(str0, str2, 5);
// 	printf("%d\n", a);
// 	a = ft_strncmp(str0, str3, 4);
// 	printf("%d\n", a);
// 	a = ft_strncmp(str3, str0, 4);
// 	printf("%d\n", a);
// 	a = ft_strncmp(str0, str1, 6);
// 	printf("%d\n", a);
// 	return (0);
// }