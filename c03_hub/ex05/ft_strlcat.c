/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/09 20:35:58 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/11 09:03:10 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

//コピー先と元の合計　strlcat = (コピー先、　コピー元、　コピー先のサイズ)　
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	dest_len;
	unsigned int	src_len;

	i = 0;
	dest_len = 0;
	src_len = 0;
	while (dest[dest_len] != '\0')
		dest_len++;
	while (src[src_len] != '\0')
		src_len++;
	if (size == 0 || dest_len >= size)
		return (size + src_len);
	while (src[i] != '\0' && dest_len + i < size - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}

// int	main(void)
// {
// 	char dest1[20] = "Hello, ";
// 	char src1[] = "world!";
// 	unsigned int result1;

// 	// テストケース 1: size が dest + src の合計より大きい場合
// 	result1 = ft_strlcat(dest1, src1, sizeof(dest1));
// 	printf("Result 1: %s, Total Length: %u\n", dest1, result1);

// 	char dest2[20] = "42";
// 	char src2[] = "Tokyo";
// 	unsigned int result2;

// 	// テストケース 2: size が dest + src の合計より小さい場合
// 	result2 = ft_strlcat(dest2, src2, 5);
// 	printf("Result 2: %s, Total Length: %u\n", dest2, result2);

// 	char dest3[20] = "C programming";
// 	char src3[] = "is fun";
// 	unsigned int result3;

// 	// テストケース 3: size が dest の長さより小さい場合
// 	result3 = ft_strlcat(dest3, src3, 2);
// 	printf("Result 3: %s, Total Length: %u\n", dest3, result3);

// 	char dest4[20] = "";
// 	char src4[] = "Empty dest";
// 	unsigned int result4;

// 	// テストケース 4: dest が空の文字列の場合
// 	result4 = ft_strlcat(dest4, src4, 20);
// 	printf("Result 4: %s, Total Length: %u\n", dest4, result4);

// 	return (0);
// }