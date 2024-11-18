/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:48:55 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/09 09:39:14 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_numeric(char *str)
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
		if ((int)str[i] >= 48 && (int)str[i] <= 57)
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

// 	i = ft_str_is_numeric("2345678");
// 	printf("%d\n", i);
// 	i = ft_str_is_numeric("ffgfhjit865etrgSDSF");
// 	printf("%d\n", i);
// 	i = ft_str_is_numeric("");
// 	printf("%d\n", i);
// 	return (0);
// }
