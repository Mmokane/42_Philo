# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 00:10:17 by mmokane           #+#    #+#              #
#    Updated: 2023/05/19 01:32:40 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=thread -g

SRCS =  philo.c philos_utils.c utils_init.c utils.c utils2.c \
		philos_actions.c ouss.c \

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@cc $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[1;32m   ---- DONE ----\033[0m"	

.c.o	:
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

all : $(NAME)

clean : 
		@rm -rf	$(OBJS)

fclean :
		@rm -rf	$(NAME)
		@rm -rf	$(OBJS)

re : clean all