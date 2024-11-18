/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 10:33:30 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/10 10:04:06 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// int	main(void)
// {
// 	static char str0[] = "apple";
// 	static char str1[] = "apple";
// 	static char str2[] = "applea";
// 	static char str3[] = "appla";
// 	static char str4[] = "appae";

// 	int a;

// 	a = ft_strcmp(str0, str1);
// 	printf("%d\n", a);
// 	a = ft_strcmp(str0, str2);
// 	printf("%d\n", a);
// 	a = ft_strcmp(str0, str3);
// 	printf("%d\n", a);
// 	a = ft_strcmp(str0, str4);
// 	printf("%d\n", a);
// 	return (0);
// }