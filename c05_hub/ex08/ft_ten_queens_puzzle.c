/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 19:17:18 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/13 19:38:24 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>  // write関数を使用するために必要なヘッダー
#include <unistd.h> // write関数を使用するために必要なヘッダー

// クイーンの配置結果を出力する関数
// 各列にあるクイーンの位置を文字に変換し、標準出力に書き出す
// 配列に格納されたクイーンの位置情報を文字列として出力する
// 10文字のクイーンの配置と改行文字を出力する
// 各クイーンの行番号を '0' に変換して出力する
// 配列の最後に改行を加えて出力完了する
void	ft_print_board(int *board)
{
	char	solution[11];
	int		i;

	i = 0;
	while (i < 10)
	{
		solution[i] = board[i] + '0';
		i++;
	}
	solution[i] = '\n';
	write(1, solution, 11);
}

// クイーンを配置する位置が安全かどうかを確認する関数
// すでに配置されたクイーンの位置を参照して、新しいクイーンが衝突しないか確認する
// 同じ行や対角線にクイーンが存在しないかチェックする
// 同じ行にクイーンがいないことを確認する
// 左下↗右上の対角線にクイーンがいないことを確認する
// 左上↘右下の対角線にクイーンがいないことを確認する
// 安全な場合1を、衝突する場合0を返す
int	ft_is_safe_function(int *board, int col, int row)
{
	int	i;

	i = 0;
	while (i < col)
	{
		if (board[i] == row || board[i] - i == row - col || board[i] + i == row
			+ col)
			return (0);
		i++;
	}
	return (1);
}

// 再帰的にクイーンを配置し、すべての解を探索する関数
// クイーンがすべての列に正しく配置された場合、解を出力しカウントを増やす
// 次の列にクイーンを配置するために、行ごとにループを回す
// 安全であればその位置にクイーンを配置し、次の列に進むために再帰呼び出しを行う
// 配置が完了するごとに解を標準出力し、パターン数をカウント
// 最終行のreturnは、その行で受けることろがなくなったときに実行される。再起で一個前の列に戻る
int	ft_put_queen(int *board, int col, int count)
{
	int	i;

	if (col == 10)
	{
		ft_print_board(board);
		return (count + 1);
	}
	i = 0;
	while (i < 10)
	{
		if (ft_is_safe_function(board, col, i))
		{
			board[col] = i;
			count = ft_put_queen(board, col + 1, count);
		}
		i++;
	}
	return (count);
}

// i = col board[i] = row の保持するboardを宣言する
// count = 最終的なパターンの合計値
// 配列boardにクイーンの配置を保持し、解の探索を開始する
// 再帰的に全パターンを探索し、最終的に解のパターン数を返す

int	ft_ten_queens_puzzle(void)
{
	int	board[10];
	int	count;

	count = 0;
	count = ft_put_queen(board, 0, count);
	return (count);
}

// int	main(void)
// {
// 	printf("count:%d\n", ft_ten_queens_puzzle());
// 	return (0);
// }