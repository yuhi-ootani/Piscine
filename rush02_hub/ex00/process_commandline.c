/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_commandline.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktei <ktei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 10:58:56 by ktei              #+#    #+#             */
/*   Updated: 2024/09/22 21:49:24 by ktei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

int	ensure_positive(int num, char **argv)
{
	int	i;

	if (argv[num][0] == '\0' || argv[num][0] == '\e')
		return (0);
	i = 0;
	while (argv[num][i])
	{
		if (!(argv[num][i] <= '9' && argv[num][i] >= '0'))
			return (0);
		i++;
	}
	return (1);
}

int	process_commandline(int argc, char **argv)
{
	if (argc == 1 || argc >= 4)
		return (0);
	if (argc == 2)
	{
		if (ensure_positive(1, argv) == 0)
			return (0);
		return (1);
	}
	else
	{
		if (ensure_positive(2, argv) == 0)
			return (0);
		return (2);
	}
}
