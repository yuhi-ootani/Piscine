/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:08:16 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/07 10:43:31 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// int	main(void)
// {
// 	int i;
// 	int k;
// 	int j;

// 	i = ft_strlen("12345");
// 	j = ft_strlen("123456789");
// 	k = ft_strlen("");

// 	printf("%d\n%d\n%d\n", i, j, k);
// }