/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 19:24:09 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/19 09:56:22 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_mul(int a, int b);
int		ft_div(int a, int b);
int		ft_mod(int a, int b);

void	ft_print_nbr(int nb)
{
	char	c;

	if (nb == INT_MIN)
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
		ft_print_nbr(nb / 10);
	c = (nb % 10) + '0';
	write(1, &c, 1);
}

int	ft_convert_int(char *str)
{
	int				sign;
	unsigned int	unb;

	sign = 1;
	unb = 0;
	while (*str == ' ' || *str == '\f' || *str == '\n' || *str == '\r'
		|| *str == '\t' || *str == '\v')
		str++;
	while (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		unb = (unb * 10) + *str - '0';
		str++;
	}
	return (sign * unb);
}

int	ft_define_operator(char *str)
{
	if (str[1] != '\0')
		return (-1);
	else if (*str == '+')
		return (0);
	else if (*str == '-')
		return (1);
	else if (*str == '*')
		return (2);
	else if (*str == '/')
		return (3);
	else if (*str == '%')
		return (4);
	return (-1);
}

int	main(int argc, char *argv[])
{
	int	left;
	int	right;
	int	index;
	int	(*p_func[5])(int, int);

	if (argc != 4)
		return (0);
	index = ft_define_operator(argv[2]);
	if (index == -1)
	{
		write(1, "0\n", 2);
		return (0);
	}
	left = ft_convert_int(argv[1]);
	right = ft_convert_int(argv[3]);
	p_func[0] = ft_add;
	p_func[1] = ft_sub;
	p_func[2] = ft_mul;
	p_func[3] = ft_div;
	p_func[4] = ft_mod;
	(*p_func[index])(left, right);
	write(1, "\n", 1);
	return (0);
}
