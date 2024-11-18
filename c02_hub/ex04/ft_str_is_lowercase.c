/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 20:52:20 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/09 17:28:42 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_lowercase(char *str)
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
		if ((int)str[i] >= 97 && (int)str[i] <= 122)
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

// 	i = ft_str_is_lowercase("hyrtsfghjuktj");
// 	printf("%d\n", i);
// 	i = ft_str_is_lowercase("DSAGDHhguif54;hls");
// 	printf("%d\n", i);
// 	i = ft_str_is_lowercase("");
// 	printf("%d\n", i);
// 	return (0);
// }