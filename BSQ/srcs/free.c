/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/25 13:23:55 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 21:48:41 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "my_header.h"

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	while (lines[i])
	{
		free(lines[i]);
		i++;
	}
	free(lines);
}

void	free_dp(int **dp, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(dp[i]);
		i++;
	}
	free(dp);
}
