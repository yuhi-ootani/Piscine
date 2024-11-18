/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 15:49:22 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/17 09:05:17 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdio.h>
#include <stdlib.h>

void				ft_show_tab(struct s_stock_str *par);

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

char	*ft_malloc_word(char *str, int size)
{
	int		i;
	char	*copy;

	i = 0;
	copy = (char *)malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	while (str[i])
	{
		copy[i] = str[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str	*result;
	int			i;
	int			j;

	result = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
	if (!result)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		result[i].size = ft_strlen(av[i]);
		result[i].str = av[i];
		result[i].copy = ft_malloc_word(av[i], result[i].size);
		if (!(result[i].copy))
		{
			j = 0;
			while (j < 1)
				free(result[j++].copy);
			free(result);
			return (NULL);
		}
		i++;
	}
	result[i].str = 0;
	return (result);
}

// 構造体の配列を表示する関数（テスト用）
void	ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		printf("Size: %d\n", par[i].size);
		printf("Original: %s\n", par[i].str);
		printf("Copy: %s\n", par[i].copy);
		i++;
	}
}

int	main(void)
{
	char		*strings1[] = {"Hello", "World", "42Tokyo"};
	t_stock_str	*array1;
	char		*strings2[] = {"", "Empty", ""};
	t_stock_str	*array2;
	char		*strings3[] = {};
	t_stock_str	*array3;

	// テスト1: 標準的な文字列配列
	printf("Test 1: Standard Input\n");
	array1 = ft_strs_to_tab(3, strings1);
	if (array1 == NULL)
		printf("Error: Memory allocation failed.\n");
	else
		ft_show_tab(array1);
	// メモリ解放
	for (int i = 0; i < 3; i++)
		free(array1[i].copy);
	free(array1);
	// テスト2: 空の文字列
	printf("\nTest 2: Empty Strings\n");
	array2 = ft_strs_to_tab(3, strings2);
	if (array2 == NULL)
		printf("Error: Memory allocation failed.\n");
	else
		ft_show_tab(array2);
	// メモリ解放
	for (int i = 0; i < 3; i++)
		free(array2[i].copy);
	free(array2);
	// テスト3: `ac == 0` の場合
	printf("\nTest 3: No Strings (ac == 0)\n");
	array3 = ft_strs_to_tab(0, strings3);
	if (array3 == NULL)
		printf("Error: Memory allocation failed.\n");
	else
		ft_show_tab(array3);
	free(array3);
	return (0);
}
