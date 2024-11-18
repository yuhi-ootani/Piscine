/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 21:15:28 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/07 10:43:28 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

// int	main(void)
// {
// 	int	a[5] = {1, 6, 3, 9, 5};
// 	int	b[6] = {3, 9, 3, 8, 7, 11};

// 	ft_sort_int_tab(a, 5);
// 	ft_sort_int_tab(b, 6);
// 	for (int i = 0; i < 5; i++)
// 	{
// 		printf("%d, ", a[i]);
// 	}
// 	printf("\n");
// 	for (int i = 0; i < 6; i++)
// 	{
// 		printf("%d, ", b[i]);
// 	}
// 	printf("\n");
// 	return (0);
// }
