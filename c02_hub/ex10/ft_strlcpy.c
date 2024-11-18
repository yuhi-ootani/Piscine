/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 10:56:18 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/12 08:17:37 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	length = 0;
	while (src[length] != '\0')
	{
		length++;
	}
	if (size == 0)
	{
		return (length);
	}
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (length);
}

// int	main(void)
// {
// 	char			dest[100];
// 	char			src[] = "banananana";
// 	unsigned int	i;

// 	i = 0;
// 	i = ft_strlcpy(dest, src, 3);
// 	printf("%s\nlength:%d", dest, i);
// 	return (0);
// }
