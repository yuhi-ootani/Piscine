# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/19 14:37:53 by oyuhi             #+#    #+#              #
#    Updated: 2024/09/23 12:01:00 by oyuhi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# Makefile for do-op program
CC = cc
CFLAGS = -Wall -Wextra -Werror
SRCS = main.c do_op.c
OBJS = $(SRCS:.c=.o)
NAME = do-op


all: $(NAME)

$(NAME) :  $(OBJS)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@rm -f $(OBJS)

fclean : clean
	@rm -f $(NAME)


re : fclean all

.PHONY : 	re fclean clean all 
