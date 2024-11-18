# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/22 21:34:25 by oyuhi             #+#    #+#              #
#    Updated: 2024/09/22 23:06:14 by oyuhi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# PRE			= ./srcs/

# HEAD		= ./includes/

# DICT		= ./dicts/
# $(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

SRCS		= main.c check_dict.c find_numbers.c process_commandline.c teens.c common_funcs.c magnitude.c output.c read_file.c

OBJS		= ${SRCS:.c=.o}

NAME		= rush-02

RM			= rm -f

CC			= cc

CFLAGS		= -Wall -Wextra -Werror


all:		${NAME}

${NAME}:	${OBJS}
	${CC} ${CFLAGS} -o ${NAME} ${OBJS}

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
