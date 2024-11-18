/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 11:47:16 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/12 19:25:31 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isspace(char c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v' || c == '\f'
		|| c == '\r');
}

int	ft_atoi(char *str)
{
	int	sign;
	int	nb;

	sign = 1;
	nb = 0;
	while (ft_isspace(*str))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		nb = (nb * 10) + (*str - '0');
		str++;
	}
	return (sign * nb);
}

// int	main(void)
// {
// 	int nb;
// 	nb = ft_atoi("   ---+-+---+1232fgsd34ab567");
// 	printf("%d\n", nb);
// 	return (0);
// }