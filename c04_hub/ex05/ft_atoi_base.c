/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 20:22:32 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/14 13:48:22 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	ft_get_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

int	ft_convert_int(char *str, char *base)
{
	int	len;
	int	result;
	int	index;

	len = 0;
	result = 0;
	index = 0;
	while (base[len])
	{
		len++;
	}
	while (*str)
	{
		index = ft_get_index(*str, base);
		if (index == -1)
			break ;
		result = result * len + index;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	if (!ft_valid_base(base))
		return (0);
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	nb = ft_convert_int(str, base);
	return (sign * nb);
}

int	main(void)
{
	// 有効なテストケース
	printf("Test 1: %d\n", ft_atoi_base("   ---+--+1234", "0123456789"));
	// Expected: -1234
	printf("Test 2: %d\n", ft_atoi_base("  +42", "0123456789"));
	// Expected: 42
	printf("Test 3: %d\n", ft_atoi_base("   -101", "01"));
	// Expected: -5 (in binary)
	printf("Test 4: %d\n", ft_atoi_base("7FFF", "0123456789ABCDEF"));
	// Expected: 32767 (in hex)
	printf("Test 5: %d\n", ft_atoi_base("poney", "poneyvif"));
	// Expected: 668 (base 8)

	// 無効なベースのテストケース
	printf("Test 6: %d\n", ft_atoi_base("42", ""));
	// Expected: 0 (empty base)
	printf("Test 7: %d\n", ft_atoi_base("42", "0"));
	// Expected: 0 (single character base)
	printf("Test 8: %d\n", ft_atoi_base("42", "012345+6789"));
	// Expected: 0 (invalid character in base)
	printf("Test 9: %d\n", ft_atoi_base("42", "01234 6789"));
	// Expected: 0 (space in base)
	printf("Test 10: %d\n", ft_atoi_base("42", "01234456789"));
	// Expected: 0 (duplicate characters in base)

	// 空の文字列や無効な文字が含まれる場合のテストケース
	printf("Test 11: %d\n", ft_atoi_base("", "0123456789"));
	// Expected: 0 (empty string)
	printf("Test 12: %d\n", ft_atoi_base("  +--invalid", "0123456789"));
	// Expected: 0 (invalid character in string)
	printf("Test 13: %d\n", ft_atoi_base("123abc", "0123456789"));
	// Expected: 123 (stops at invalid character 'a')
	printf("Test 14: %d\n", ft_atoi_base("-123 456", "0123456789"));
	// Expected: -123 (stops at space)
	printf("Test 15: %d\n", ft_atoi_base("  +123", "0123456789"));
	// Expected: 123 (with leading spaces)

	return (0);
}