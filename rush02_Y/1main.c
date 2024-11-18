/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1main.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 18:10:39 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/22 20:46:37 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

// // 40桁以上の入力に対応し、該当するキーを探す関数
// int	check_large_number(char *nbr, t_dict_entry *dict, int dict_size)
// {
// 	int			len;
// 	char		large_key[100];
// 	const char	*unit = find_unit_by_string(large_key, dict, dict_size);

// 	len = ft_strlen(nbr);
// 	// 40桁以上の入力の場合、キーを探す
// 	if (len >= 40)
// 	{
// 		// 入力の最初の部分をキーとして作成
// 		strncpy(large_key, nbr, 40);
// 		large_key[40] = '\0'; // 終端文字を追加
// 		// find_unit_by_stringで一致するキーを探す
// 		if (!unit)
// 		{
// 			// 該当するキーが見つからなければエラーを返す
// 			ft_putstr("Too big!!\n");
// 			return (0); // エラーコードを返す
// 		}
// 	}
// 	return (1); // 正常にキーが見つかった場合
// }

int	main(int argc, char **argv)
{
	int	dict_size;

	t_dict_entry dict[100]; // 仮に100行までと仮定
	dict_size = 0;
	if (argc < 2 || argc > 3)
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// デフォルト辞書を使う場合
	if (argc == 2)
	{
		read_dictionary("numbers.dict", dict, &dict_size);
	}
	else
	{
		// コマンドライン引数で辞書を指定する場合
		read_dictionary(argv[1], dict, &dict_size);
	}
	// 数値に対応するキーを辞書から検索
	process_large_number(argv[argc - 1], dict, dict_size);
	return (0);
}

// int	main(int argc, char **argv)
// {
// 	char			*number_str;
// 	t_dict_entry	*dict;
// 	int				dict_size;

// 	char *dict_file = "numbers.dict"; // デフォルトの辞書ファイル
// 	// コマンドライン引数のチェック
// 	if (argc == 2)
// 		number_str = argv[1];
// 	else if (argc == 3)
// 	{
// 		dict_file = argv[1];
// 		number_str = argv[2];
// 	}
// 	else
// 	{
// 		ft_putstr("Error\n");
// 		return (1);
// 	}
// 	if (!is_valid_number(number_str))
// 	{
// 		ft_putstr("Error\n");
// 		return (1);
// 	}
// 	dict = read_dictionary(dict_file, &dict_size);
// 	if (!dict)
// 	{
// 		ft_putstr("Dict Error\n");
// 		return (1);
// 	}
// 	if (!number_to_words(number_str, dict, dict_size))
// 	{
// 		ft_putstr("Dict Error\n");
// 		free_dictionary(dict, dict_size);
// 		return (1);
// 	}
// 	free_dictionary(dict, dict_size);
// 	return (0);
// }
