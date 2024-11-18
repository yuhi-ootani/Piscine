/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktei <ktei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:11:20 by ktei              #+#    #+#             */
/*   Updated: 2024/09/22 23:25:09 by ktei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sources.h"

int	main(int argc, char *argv[])
{
	char	*dict;

	if (process_commandline(argc, argv) == 0)
	{	
		write(1, "Error\n", 6);
		return (0);
	}
	if (process_commandline(argc, argv) == 1)
		dict = read_file("numbers.dict");
	if (process_commandline(argc, argv) == 2)
	{
		dict = read_file(argv[1]);
		if (!dict)
			return (0);
	}
	if (check_dict(dict) == -1 || check_digits(argc, argv) == -1)
	{
		write(1, "Dict Error\n", 11);
		return (0);
	}
	output_origin(dict, argc, argv);
	write(1, "\n", 1);
	free(dict);
	return (0);
}
