/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 11:25:33 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/09 17:28:24 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_put_char(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	static char		*hex = "0123456789abcdef";
	int				i;
	unsigned char	ch;

	i = 0;
	while (str[i] != '\0')
	{
		ch = (unsigned char)str[i];
		if (ch >= ' ' && ch <= '~')
		{
			ft_put_char(ch);
		}
		else
		{
			write(1, "\\", 1);
			ft_put_char(hex[ch / 16]);
			ft_put_char(hex[ch % 16]);
		}
		i++;
	}
}

// int	main(void)
// {
// 	static char	oa[] = "Coucou\ntu vas bien ?";
// 	static char	lb[] = "Coucou\etu vas bien ?";
// 	static char	o9[] = "Coucou\ttu vas bien ?";

// 	ft_putstr_non_printable(oa);
// 	write(1, "\n", 1);
// 	ft_putstr_non_printable(lb);
// 	write(1, "\n", 1);
// 	ft_putstr_non_printable(o9);
// 	write(1, "\n", 1);
// 	return (0);
// }
