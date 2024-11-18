/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_header.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/23 19:53:21 by oyuhi             #+#    #+#             */
/*   Updated: 2024/09/25 23:35:51 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MY_HEADER_H
# define MY_HEADER_H

# include <aio.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define INITIAL_BUFFER_SIZE 1024

typedef struct s_map_info
{
	char				empty;
	char				obstacle;
	char				full;
	unsigned long long	rows;
	int					cols;
	int					max_size;
	int					max_x;
	int					max_y;
}						t_map_info;

// read_map
char					*cpy_buffer(char *buffer, char *new_buffer,
							size_t total_size);
char					*if_expand_buf(char *buffer, size_t *buffer_size,
							size_t *total_size, ssize_t *bytes_read);
char					*read_stdin(void);

// read file
int						get_file_size(const char *filename);
char					*read_file_content(const char *filename,
							int total_size);
char					*read_file_to_string(const char *filename);

// split

int						count_lines(char *str);
char					**allocate_lines(char *str);
void					copy_lines(char **map, char *str);
char					**split_into_lines(char *str);

// is_valid_map
int						is_valid_map(char **map, t_map_info *map_info);
int						parse_first_line(char *line, t_map_info *map_info);

// find square1
void					map_square(char **map, t_map_info *map_info);
void					process_row(int **dp, int i, char **map,
							t_map_info *map_info);
void					fill_dp(char **map, int **dp, t_map_info *map_info);
int						**malloc_dp(int rows, int cols);
void					find_square(char **map, t_map_info *map_info);

// free
void					free_lines(char **lines);
void					free_dp(int **dp, int rows);

// function1.c
int						ft_min_of_three(int a, int b, int c);
void					ft_putchar(char c);
void					ft_putstr(char *str);

// function2.c
char					*ft_strncpy(char *dest, char *src, unsigned int n);
size_t					ft_strlen(char *str);
void					ft_strcpy(char *dest, char *str);
char					*ft_strdup(char *src);

#endif
