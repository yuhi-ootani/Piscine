/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/18 20:49:28 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/19 09:50:49 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_print_nbr(int nb);

void	ft_add(int a, int b)
{
	int	result;

	result = a + b;
	ft_print_nbr(result);
}

void	ft_sub(int a, int b)
{
	int	result;

	result = a - b;
	ft_print_nbr(result);
}

void	ft_mul(int a, int b)
{
	int	result;

	result = a * b;
	ft_print_nbr(result);
}

void	ft_div(int a, int b)
{
	int	result;

	if (b == 0)
	{
		write(1, "Stop : division by zero", 23);
		return ;
	}
	result = a / b;
	ft_print_nbr(result);
}

void	ft_mod(int a, int b)
{
	int	result;

	if (b == 0)
	{
		write(1, "Stop : modulo by zero", 21);
		return ;
	}
	result = a % b;
	ft_print_nbr(result);
}
