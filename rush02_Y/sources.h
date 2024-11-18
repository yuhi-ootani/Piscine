#ifndef SOURCES_H
# define SOURCES_H

# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_dict_entry
{
	char *key;   // unsigned int を扱うために char* に変更
	char *value; // 数字に対応する文字列
}			t_dict_entry;

// 2
void		read_dictionary(char *filename, t_dict_entry *dict, int *dict_size);

// 3
int			parse_line(char *line, t_dict_entry *entry);
int			parse_key(char *line, int *i, char **key_part);
int			parse_value(char *line, int *i, char **value_part);
char		*copy_substring(char *str, int start, int end);
int			skip_spaces(char *str, int i);

// 4
void		process_group(char *buffer, int grp_cnt, t_dict_entry *dict,
				int d_size);
void		process_number_groups(char *padded_nbr, int grp_cnt,
				t_dict_entry *dict, int d_size);
char		*pad_number(char *nbr);
void		process_large_number(char *nbr, t_dict_entry *dict, int d_size);

// 5

// 6
void		convert_below_1000(unsigned long long num, t_dict_entry *dict,
				int dict_size);
void		append_unit_and_space(int grp_cnt, t_dict_entry *dict, int d_size);

// 7
char		*ft_itoa(unsigned long long num);
const char	*find_word(unsigned long long num, t_dict_entry *dict,
				int dict_size);
char		*find_unit_by_string(const char *key_str, t_dict_entry *dict,
				int dict_size);

// 8
int			ft_strlen(char *str);
char		*ft_strdup(char *src);
int			ft_strcmp(const char *s1, const char *s2);
char		*ft_strcpy(char *dest, const char *src);
char		*ft_strncpy(char *dest, char *src, unsigned int n);

// 9
void		ft_putstr(const char *str);
void		ft_putchar(char c);
int			ft_atoi(const char *str);
void		*ft_memset(void *s, int c, size_t n);

#endif