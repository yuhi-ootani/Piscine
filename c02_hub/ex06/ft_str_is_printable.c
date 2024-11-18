/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 21:01:17 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/10 11:09:38 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_printable(char *str)
{
	int	i;

	if (str[0] == '\0')
	{
		return (1);
	}
	i = 0;
	while (str[i] != '\0')
	{
		if ((int)str[i] >= 32 && (int)str[i] <= 126)
		{
			i++;
			continue ;
		}
		return (0);
	}
	return (1);
}

int	main(void)
{
	int i;

	i = ft_str_is_printable("!\"#$%&'()*+,-./012389:;=>?@ABCVWXYZ");
	printf("%d\n", i);
	i = ft_str_is_printable("[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~");
	printf("%d\n", i);
	i = ft_str_is_printable(" ");
	printf("%d\n", i);
	i = ft_str_is_printable("\t");
	printf("%d\n", i);
	return (0);
}