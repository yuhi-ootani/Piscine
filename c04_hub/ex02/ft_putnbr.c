/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:34:31 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/12 13:52:20 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	c = '0' + (nb % 10);
	write(1, &c, 1);
}

// int	main(void)
// {
// 	ft_putnbr(42);
// 	write(1, "\n", 1);
// 	ft_putnbr(-2147483648);
// 	write(1, "\n", 1);
// 	ft_putnbr(-2147483647);
// 	write(1, "\n", 1);
// 	ft_putnbr(2147483647);
// 	write(1, "\n", 1);
// 	ft_putnbr(0);
// 	write(1, "\n", 1);
// 	return (0);
// }