/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 09:34:18 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/18 11:43:57 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_is_separator(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

char	**ft_malloc_result(char *str, char *charset)
{
	int		in_word;
	int		count;
	int		i;
	char	**result;

	in_word = 0;
	count = 0;
	i = 0;
	while (str[i])
	{
		if (ft_is_separator(str[i], charset))
			in_word = 0;
		else if (in_word == 0)
		{
			count++;
			in_word = 1;
		}
		i++;
	}
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (NULL);
	result[count] = 0;
	return (result);
}

char	*ft_malloc_word(char *str, int start, int size)
{
	int		i;
	char	*word;

	i = 0;
	word = (char *)malloc(sizeof(char) * (size + 1));
	if (!word)
		return (NULL);
	while (i < size)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	int		i;
	int		start;
	int		index;
	char	**result;

	i = 0;
	index = 0;
	result = ft_malloc_result(str, charset);
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (!ft_is_separator(str[i], charset))
		{
			start = i;
			while (str[i] && !ft_is_separator(str[i], charset))
				i++;
			result[index] = ft_malloc_word(str, start, i - start);
			if (!result[index++])
				return (NULL);
		}
		else
			i++;
	}
	return (result);
}

// int	main(void)
// {
// 	// テストケース 1: 基本的な区切り文字列
// 	printf("Test Case 1:\n");
// 	char str1[] = "apple,banana;cherry!orange";
// 	char charset1[] = ",;!";
// 	char **result1 = ft_split(str1, charset1);

// 	int i = 0;
// 	while (result1[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result1[i]);
// 		free(result1[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result1); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 2: 空の文字列
// 	printf("Test Case 2:\n");
// 	char str2[] = "";
// 	char charset2[] = ",;!";
// 	char **result2 = ft_split(str2, charset2);

// 	i = 0;
// 	while (result2[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result2[i]);
// 		free(result2[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result2); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 3: 区切り文字だけの文字列
// 	printf("Test Case 3:\n");
// 	char str3[] = ",,,;;;!!!";
// 	char charset3[] = ",;!";
// 	char **result3 = ft_split(str3, charset3);

// 	i = 0;
// 	while (result3[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result3[i]);
// 		free(result3[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result3); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 4: 区切り文字がない場合
// 	printf("Test Case 4:\n");
// 	char str4[] = "nodelimiters";
// 	char charset4[] = ":,;!";
// 	char **result4 = ft_split(str4, charset4);

// 	i = 0;
// 	while (result4[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result4[i]);
// 		free(result4[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result4); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 5: 区切り文字が連続する場合
// 	printf("Test Case 5:\n");
// 	char str5[] = "this,,is,a,,test";
// 	char charset5[] = ",";
// 	char **result5 = ft_split(str5, charset5);

// 	i = 0;
// 	while (result5[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result5[i]);
// 		free(result5[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result5); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 6: 先頭と末尾に区切り文字がある場合
// 	printf("Test Case 6:\n");
// 	char str6[] = ",apple,banana,cherry,";
// 	char charset6[] = ",";
// 	char **result6 = ft_split(str6, charset6);

// 	i = 0;
// 	while (result6[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result6[i]);
// 		free(result6[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result6); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 7: 文字列全体が区切り文字で囲まれている場合
// 	printf("Test Case 7:\n");
// 	char str7[] = "::apple::banana::cherry::";
// 	char charset7[] = ":";
// 	char **result7 = ft_split(str7, charset7);

// 	i = 0;
// 	while (result7[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result7[i]);
// 		free(result7[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result7); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 8: 区切り文字が複数種類ある場合
// 	printf("Test Case 8:\n");
// 	char str8[] = "apple;banana,cherry orange";
// 	char charset8[] = ";, ";
// 	char **result8 = ft_split(str8, charset8);

// 	i = 0;
// 	while (result8[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result8[i]);
// 		free(result8[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result8); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 9: 区切り文字が空白だけの場合
// 	printf("Test Case 9:\n");
// 	char str9[] = "word1 word2 word3";
// 	char charset9[] = " ";
// 	char **result9 = ft_split(str9, charset9);

// 	i = 0;
// 	while (result9[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result9[i]);
// 		free(result9[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result9); // 配列自体のメモリ解放
// 	printf("\n");

// 	// テストケース 10: 全ての文字が区切り文字でない場合
// 	printf("Test Case 10:\n");
// 	char str10[] = "abcd";
// 	char charset10[] = ",;!";
// 	char **result10 = ft_split(str10, charset10);

// 	i = 0;
// 	while (result10[i])
// 	{
// 		printf("Word %d: %s\n", i + 1, result10[i]);
// 		free(result10[i]); // メモリ解放
// 		i++;
// 	}
// 	free(result10); // 配列自体のメモリ解放
// 	printf("\n");

// 	return (0);
// }