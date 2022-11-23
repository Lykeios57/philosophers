# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcacoilo <mcacoilo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/22 01:31:18 by mcacoilo          #+#    #+#              #
#    Updated: 2022/11/22 16:51:11 by mcacoilo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philosophers

SRCS =	philo.c \
		philo_utils.c \
		put.c

INC = philosophers.h

OBJS = ${SRCS:.c=.o}

CC = gcc

CFLAGS = -Wall -Wextra -Werror -pthread

all: $(NAME)

$(NAME): $(OBJS) $(INC)
	@$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean:
	-@rm -rf $(OBJS)

fclean: clean
	-@rm -rf $(NAME)

re: fclean all
