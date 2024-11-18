/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:15:28 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/07 10:43:29 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int	i;
	int	half;
	int	temp;

	i = 0;
	temp = 0;
	half = size / 2;
	while (i < half)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

// int	main(void)
// {
// 	int	a[5] = {1, 2, 3, 4, 5};
// 	int	b[6] = {1, 2, 3, 4, 5, 6};

// 	ft_rev_int_tab(a, 5);
// 	ft_rev_int_tab(b, 6);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("%d", a[i]);
// 	}
// 	printf("\n");
// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("%d", b[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }
