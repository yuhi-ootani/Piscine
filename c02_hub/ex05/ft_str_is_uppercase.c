/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:55:50 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/09 17:28:38 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_uppercase(char *str)
{
	int		i;
	char	c;

	if (str[0] == '\0')
	{
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		c = str[i];
		if ((int)str[i] >= 65 && (int)str[i] <= 90)
		{
			i++;
			continue ;
		}
		return (0);
	}
	return (1);
}

// int	main(void)
// {
// 	int i;

// 	i = ft_str_is_uppercase("SDFGHJTYERD");
// 	printf("%d\n", i);
// 	i = ft_str_is_uppercase("DSAGDHhg32uifhls");
// 	printf("%d\n", i);
// 	i = ft_str_is_uppercase("");
// 	printf("%d\n", i);
// 	return (0);
// }