/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 16:14:35 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/18 16:31:48 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
	{
		(*f)(tab[i]);
		i++;
	}
}

// #include <unistd.h>

// void	ft_putnbr(int nb)
// {
// 	char	c;

// 	if (nb < 0)
// 	{
// 		write(1, "-", 1);
// 		nb = -nb;
// 	}
// 	if (nb >= 10)
// 	{
// 		ft_putnbr(nb / 10);
// 	}
// 	c = (nb % 10) + '0';
// 	write(1, &c, 1);
// }

// int	main(void)
// {
// 	int	tab[] = {1, 2, 3, 4, 5};
// 	int	length;

// 	length = 5;
// 	ft_foreach(tab, length, &ft_putnbr);
// 	write(1, "\n", 1);
// 	return (0);
// }
