/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 08:32:03 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/09 11:37:17 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	is_alpanumeric(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0'
			&& c <= '9'));
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((i == 0 || !is_alpanumeric(str[i - 1])) && (str[i] >= 'a'
				&& str[i] <= 'z'))
		{
			str[i] = str[i] - 32;
		}
		else if (!is_alpanumeric(str[i - 1]) && (str[i] >= 'A'
				&& str[i] <= 'Z'))
		{
			i++;
			continue ;
		}
		else if (is_alpanumeric(str[i - 1]) && (str[i] >= 'A' && str[i] <= 'Z'))
		{
			str[i] = str[i] + 32;
		}
		i++;
	}
	return (str);
}

// int	main(void)
// {
// 	char str0[] = "salut, comment tu vas ? "
// 					"42mots quarante-deux; cinquante+et+un";
// 	char str1[] = "my name is YUHI Otani !a !b !c";

// 	printf("%s\n", ft_strcapitalize(str0));
// 	printf("%s\n", ft_strcapitalize(str1));
// 	return (0);
// }