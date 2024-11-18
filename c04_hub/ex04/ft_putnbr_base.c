/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 14:56:25 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/13 23:58:54 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_nbr(unsigned int nbr, char *base, unsigned int len)
{
	char	c;

	if (nbr >= len)
	{
		ft_print_nbr(nbr / len, base, len);
	}
	c = base[nbr % len];
	write(1, &c, 1);
}

int	ft_valid_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (!base[0] || !base[1])
		return (0);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	len;
	unsigned int	unbr;

	len = 0;
	if (!ft_valid_base(base))
		return ;
	while (base[len])
	{
		len++;
	}
	if (nbr < 0)
	{
		write(1, "-", 1);
		unbr = (unsigned int)(-nbr);
	}
	else
		unbr = (unsigned int)nbr;
	ft_print_nbr(unbr, base, len);
}

// int	main(void)
// {
// 	ft_putnbr_base(-42, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-42, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-42, "0123456789ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-42, "poneyvif");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "0123456789");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "01");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "0123456789ABCDEF");
// 	write(1, "\n", 1);
// 	ft_putnbr_base(-2147483648, "poneyvif");
// 	write(1, "\n", 1);
// 	return (0);
// }