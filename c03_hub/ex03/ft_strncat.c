/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:26:58 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/10 09:25:16 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	while (src[j] != '\0' && j < nb)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (dest);
}

// int	main(void)
// {
// 	static char dest1[100] = "Hello ";
// 	printf("before:%s\n", dest1);
// 	printf("after :%s\n", ft_strncat(dest1, "World!", 3));

// 	static char dest2[100] = "Hello ";
// 	printf("before:%s\n", dest2);
// 	printf("after :%s\n", ft_strncat(dest2, "World!", 10));
// 	return (0);
// }