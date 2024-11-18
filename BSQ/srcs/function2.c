/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 15:20:13 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 23:33:24 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

void	ft_strcpy(char *dest, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		dest[i] = str[i];
		i++;
	}
	dest[i] = '\0';
}

char	*ft_strdup(char *src)
{
	int		len;
	char	*copy;

	if (src == NULL)
		return (NULL);
	len = ft_strlen(src);
	copy = (char *)malloc(sizeof(char) * (len + 1));
	if (!copy)
		return (NULL);
	ft_strcpy(copy, src);
	return (copy);
}
