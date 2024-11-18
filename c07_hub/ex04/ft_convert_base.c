/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:07:57 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/16 11:04:37 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

char	*ft_itoa_base(long unbr, char *base_to, int sign);
int		ft_in_base(char c, char *base);
int		ft_atoi_base(char *str, char *base);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
	{
		len++;
	}
	return (len);
}

int	ft_check_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) <= 1)
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == ' ')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j++])
				return (0);
		}
		i++;
	}
	return (1);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	long	nbr_int;
	int		sign;
	char	*nbr_char;

	sign = 0;
	if (!ft_check_base(base_from) || !ft_check_base(base_to))
		return (NULL);
	nbr_int = ft_atoi_base(nbr, base_from);
	if (nbr_int < 0)
	{
		sign = 1;
		nbr_int *= -1;
	}
	nbr_char = ft_itoa_base(nbr_int, base_to, sign);
	return (nbr_char);
}

// int	main(void)
// {
// 	char *result;

// 	// 10進数から16進数への変換 (expected: 2A)
// 	result = ft_convert_base("   +42", "0123456789", "0123456789ABCDEF");
// 	if (result != NULL)
// 		printf("'   +42' -> %s (expected: 2A)\n", result);
// 	free(result);

// 	// 16進数から10進数への変換 (expected: -42)
// 	result = ft_convert_base("   ---+--+2A", "0123456789ABCDEF", "0123456789");
// 	if (result != NULL)
// 		printf("'   ---+--+2A' -> %s (expected: -42)\n", result);
// 	free(result);

// 	// 10進数から2進数への変換 (expected: -110110)
// 	result = ft_convert_base("   -54", "0123456789", "01");
// 	if (result != NULL)
// 		printf("'   -54' -> %s (expected: -110110)\n", result);
// 	free(result);

// 	// 2進数から10進数への変換 (expected: 7)
// 	result = ft_convert_base("   +111", "01", "0123456789");
// 	if (result != NULL)
// 		printf("'   +111' -> %s (expected: 7)\n", result);
// 	free(result);

// 	// 無効な文字列 (途中で文字が混ざる) (expected: 0)
// 	result = ft_convert_base("   ---+--+d", "0123456789", "0123456789ABCDEF");
// 	if (result != NULL)
// 		printf("'   ---+--+d' -> %s (expected: 0)\n", result);
// 	free(result);

// 	// エッジケース (0の変換) (expected: 0)
// 	result = ft_convert_base("   +0", "0123456789", "01");
// 	if (result != NULL)
// 		printf("'   +0' -> %s (expected: 0)\n", result);
// 	free(result);

// 	// エッジケース (負の最大値を16進数に変換) (expected: -80000000)
// 	result = ft_convert_base("   -2147483648", "0123456789",
// 			"0123456789ABCDEF");
// 	if (result != NULL)
// 		printf("'   -2147483648' -> %s (expected: -80000000)\n", result);
// 	free(result);

// 	// 10進数からponeyvifの8進数への変換 (expected: ofe)
// 	result = ft_convert_base("   +123", "0123456789", "poneyvif");
// 	if (result != NULL)
// 		printf("'   +123' -> %s (expected: ofe)\n", result);
// 	free(result);

// 	// poneyvifの8進数から10進数への変換 (expected: 313)
// 	result = ft_convert_base("   +yfo", "poneyvif", "0123456789");
// 	if (result != NULL)
// 		printf("'   +yfo' -> %s (expected: 313)\n", result);
// 	free(result);

// 	// poneyvifの8進数から16進数への変換 (expected: 37)
// 	result = ft_convert_base("   +pif", "poneyvif", "0123456789ABCDEF");
// 	if (result != NULL)
// 		printf("'   +pif' -> %s (expected: 37)\n", result);
// 	free(result);

// 	// baseに無効な+文字がある (expected: NULL)
// 	result = ft_convert_base("   +pif", "poneyvif", "0123456789ABCDE+");
// 	if (result == NULL)
// 		printf("ベースに無効な文字があります。\n");
// 	free(result);

// 	// baseに無効な空白文字がある (expected: NULL)
// 	result = ft_convert_base("   +pif", "poneyvif", "0123456789ABCDE ");
// 	if (result == NULL)
// 		printf("ベースに無効な文字があります。\n");
// 	free(result);

// 	// baseに無効な重複文字がある (expected: NULL)
// 	result = ft_convert_base("   +pif", "poneyvif", "0123456789ABCDEE");
// 	if (result == NULL)
// 		printf("ベースに無効な文字があります。\n");
// 	free(result);

// 	return (0);
// }