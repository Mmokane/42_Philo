# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmokane <mmokane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/05 00:10:17 by mmokane           #+#    #+#              #
#    Updated: 2023/05/05 00:17:22 by mmokane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc 

CFLAGS = -Wall -Werror -Wextra #-fsanitize=address -g

SRCS = 

OBJS = $(SRCS:.c=.o)

$(NAME) : $(OBJS)
		@echo "\033[1;32m---- COMPILING! ----\033[0m"
		@cc $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "\033[1;32m   ---- DONE ----\033[0m"	

all : $(NAME)

clean : 
		@rm -rf	$(OBJS)

fclean :
		@rm -rf	$(NAME)

re : clean all