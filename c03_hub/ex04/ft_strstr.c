/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 14:40:06 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/18 13:06:53 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdio.h>

int	ft_is_same(char *str, char *to_find, int count, int i)
{
	int	j;

	j = 0;
	while ((j < count) && (str[i + j] == to_find[j]))
	{
		j++;
	}
	if (j == count)
	{
		return (1);
	}
	return (0);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	count;

	count = 0;
	while (to_find[count] != '\0')
	{
		count++;
	}
	if (count == 0)
		return (str);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find[0])
		{
			if (ft_is_same(str, to_find, count, i))
				return (str + i);
		}
		i++;
	}
	return (NULL);
}

// int	main(void)
// {
// 	static char haystack[] = "dcbaaaaabcd";
// 	static char needle1[] = "abc";
// 	static char needle2[] = "ggg";
// 	char *address1 = ft_strstr(haystack, needle1);
// 	char *address2 = ft_strstr(haystack, needle2);
// 	printf("%s\n", address1);
// 	printf("%s\n", address2);
// 	return (0);
// }