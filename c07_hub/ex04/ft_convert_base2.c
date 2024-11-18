/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 23:08:01 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/16 10:55:01 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_strlen(char *str);

// convert long number into base_to style
// len = sign + 1; is for unbr == 0
char	*ft_itoa_base(long unbr, char *base_to, int sign)
{
	long	temp;
	int		base_len;
	int		len;
	char	*result;

	base_len = ft_strlen(base_to);
	temp = unbr / base_len;
	len = sign + 1;
	while (temp)
	{
		len++;
		temp /= base_len;
	}
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len] = '\0';
	while (len-- > sign)
	{
		result[len] = base_to[unbr % base_len];
		unbr /= base_len;
	}
	if (sign)
		result[0] = '-';
	return (result);
}

// return index number which is equal to decimal number
int	ft_in_base(char c, char *base)
{
	int	len;
	int	i;

	len = ft_strlen(base);
	i = 0;
	while (i < len)
	{
		if (c == base[i])
			return (i);
		i++;
	}
	return (-1);
}

// convert str into decimal number
int	ft_atoi_base(char *str, char *base)
{
	int		sign;
	long	result;
	int		base_len;

	sign = 1;
	result = 0;
	base_len = ft_strlen(base);
	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\r' || *str == '\t')
		str++;
	while (*str == '+' || *str == '-' || *str == ' ')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (ft_in_base(*str, base) != -1)
	{
		result = result * base_len + ft_in_base(*str, base);
		str++;
	}
	return (sign * result);
}
