# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/17 11:16:24 by oyuhi             #+#    #+#              #
#    Updated: 2024/10/22 14:09:16 by oyuhi            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#　complie with option
CC  =  cc 
CFLAGS = -Wall -Wextra -Werror

# archaive and ranlib function
AR  =  ar rc
RANLIB =  ranlib 

# source files and objects files and directory
SRCS = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJS = srcs/ft_putchar.o srcs/ft_swap.o srcs/ft_putstr.o srcs/ft_strlen.o srcs/ft_strcmp.o
INCDIR = includes


# The default target that compiles the libft.a library.
all: libft.a

# This rule creates the libft.a library by archiving the object files.
# It automatically compiles .o files from the .c files if they don't exist.
libft.a: $(OBJS)
	$(AR) libft.a $(OBJS)
	$(RANLIB) libft.a

# Compile each .c file into its corresponding .o file.
# %: matches any string (used for pattern matching).
# $<: the first dependency (source .c file).
# $@: the target file (.o file to be created).
# -I: indicate which directory has a header file.
srcs/%.o: srcs/%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(INCDIR)

# Remove object files.
clean: 
	rm -f $(OBJS)


# Remove object files and the library.
#fclean = clean + remove libft.a
fclean: clean
	rm -f libft.a

# Rebuild everything (remove and then recreate).
re: fclean all