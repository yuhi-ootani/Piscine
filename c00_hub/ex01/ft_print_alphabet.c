/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_alphabet.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 14:53:49 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/06 20:41:09 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_alphabet(void)
{
	int		i;
	char	a;

	a = 'a';
	i = 0;
	while (i < 26)
	{
		write(1, &a, 1);
		a++;
		i++;
	}
}

// int	main(void)
// {
// 	ft_print_alphabet();
// 	return (0);
// }
