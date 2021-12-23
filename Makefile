# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aelousse <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/24 14:18:24 by aelousse          #+#    #+#              #
#    Updated: 2021/11/27 16:01:10 by aelousse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libftprintf.a
INC = ft_printf.h
SRCS = ft_printf.c ft_printf_utils.c ft_printf_utils2.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
CC = gcc
RM = rm -rf
AR = @ar -rcs

all: $(NAME)

$(NAME): $(OBJS) $(INC)
		$(AR) $(NAME) $(OBJS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean: clean
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)

re: fclean all
