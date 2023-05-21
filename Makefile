# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 00:10:17 by mmokane           #+#    #+#              #
#    Updated: 2023/05/19 22:37:23 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=thread -g3

SRCS =  philo.c source/philos_utils.c source/utils_init.c source/utils.c source/utils2.c \
		source/philos_actions.c \

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