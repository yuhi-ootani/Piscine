/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:29:18 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/09 09:45:34 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] = str[i] - 32;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str1[] = "poiuytrewqlkjhgfdsa";
// 	char str2[] = "mnbv!@#$123456CXZ";
// 	char str3[] = "";

// 	printf("%s\n", ft_strupcase(str1));
// 	printf("%s\n", ft_strupcase(str2));
// 	printf("%s\n", ft_strupcase(str3));
// 	return (0);
// }