/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 19:28:42 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/09 09:38:19 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_alpha(char *str)
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
		if (((int)str[i] >= 65 && (int)str[i] <= 90) || ((int)str[i] >= 97
				&& (int)str[i] <= 122))
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
// 	int	i;

// 	i = ft_str_is_alpha("saflgkh48ytg");
// 	printf("%d\n", i);
// 	i = ft_str_is_alpha("DSAGDHhguifhls");
// 	printf("%d\n", i);
// 	i = ft_str_is_alpha("");
// 	printf("%d\n", i);
// 	return (0);
// }
