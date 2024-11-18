/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sources.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktei <ktei@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/21 09:12:48 by ktei              #+#    #+#             */
/*   Updated: 2024/09/22 23:25:20 by ktei             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOURCES_H
# define SOURCES_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	check_dict2(char *dict, int *i, int *flag);
int		check_dict(char *dict);
int		check_digits(int argc, char *argv[]);
int		ft_atoi_p(char *str);
int		ft_len_nbr(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strncpy(char *dest, char *src, unsigned int n);
char	*consult_dict(char *str, char *to_find);
void	put_words(char *found, int flag);
int		point_to_nbr(char input, int digits, char *dict, int flag);
char	*search_teens(char *dict, char *input);
int		output_teens(char *dict, char *input, int k);
int		main(int argc, char *argv[]);
void	output_origin(char *dict, int argc, char *argv[]);
void	output_small(char *dict, int digits, char *input);
void	output_large(char *dict, char *input);
int		point_zero(char *dict);
int		ensure_positive(int num, char **argv);
int		process_commandline(int argc, char **argv);
char	*read_file(const char *filename);
void	devided_by_three(char *buffer, int start, char *dict);

#endif