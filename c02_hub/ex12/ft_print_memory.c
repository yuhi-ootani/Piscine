/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/08 14:11:02 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/16 15:33:59 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

//与えられたDigits分左から１６進数を出力する。numが０でもdigitsの数字に値するまで再起する。
void	ft_print_hex(unsigned long num, int digits)
{
	static char	*hex = "0123456789abcdef";
	char		c;

	if (num >= 16 || digits > 1)
	{
		ft_print_hex(num / 16, digits - 1);
	}
	c = hex[num % 16];
	write(1, &c, 1);
}

//引数の１６バイトの文字列をサイズに達するまで、一文字一文字２桁の１６進数で出力する。
void	ft_print_hex_pair(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && i < size)
	{
		ft_print_hex(str[i], 2);
		if (i % 2 == 1)
			write(1, " ", 1);
		i++;
	}
	while (i < 16)
	{
		if (i % 2 == 1)
		{
			write(1, "   ", 3);
		}
		else
		{
			write(1, "  ", 2);
		}
		i++;
	}
}

void	ft_print_char16(unsigned char *str, unsigned int size)
{
	unsigned int	i;

	i = 0;
	while (i < 16 && i < size)
	{
		if (str[i] >= 32 && str[i] <= 126)
		{
			write(1, &str[i], 1);
		}
		else
		{
			write(1, ".", 1);
		}
		i++;
	}
}

void	ft_print16(void *addr, unsigned int size)
{
	unsigned long	address;
	unsigned char	*mem;

	mem = (unsigned char *)addr;
	address = (unsigned long)addr;
	ft_print_hex(address, 16);
	write(1, ": ", 2);
	ft_print_hex_pair(mem, size);
	ft_print_char16(mem, size);
	write(1, "\n", 1);
}

//文字列を１６文字ごと（１６バイトごと）にメモリアドレスを区切る関数
void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	offset;

	offset = 0;
	while (size > offset)
	{
		ft_print16(addr + offset, size - offset);
		offset += 16;
	}
	return (addr);
}

int	main(void)
{
	static char addr[] = "Bonjour les aminches\v\b\tc\v est fo"
							"u\ttout\vce qu on peut faire avec\b\v\n"
							"print_memory\v\b..lol.lol\t .";
	static char addr1[] = "Chapter XV Exercise 12 : ft_print_memory";

	ft_print_memory(&addr, 92);
	write(1, "\n", 1);
	ft_print_memory(&addr1, 40);
	return (0);
}