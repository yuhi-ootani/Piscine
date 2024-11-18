# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/25 22:56:06 by oyuhi             #+#    #+#              #
#    Updated: 2024/09/25 23:35:13 by oyuhi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


SRCS        = srcs/a_main.c srcs/b_read_map_stdin.c srcs/c_read_map_file.c srcs/d_split_into_lines.c srcs/e_check_map.c srcs/find_square.c srcs/free.c srcs/function1.c srcs/function2.c
OBJS		= ${SRCS:.c=.o}

NAME		= bsq

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror


all:		${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			$(RM) ${OBJS}

fclean:		clean
			$(RM) ${NAME}

re:			fclean all

.PHONY:		all clean fclean re