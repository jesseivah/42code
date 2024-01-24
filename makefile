# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/09 15:57:54 by jebitrus          #+#    #+#              #
#    Updated: 2023/10/09 15:58:06 by jebitrus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	= client.c server.c

OBJS	:= $(SRCS:%.c=%.o)

NAME	= minitalk

CC		= cc
RM		= rm -f

CFLAGS 	= -Wall -Wextra -Werror

all:		${NAME}

%.o:	%.c
		${CC} ${CFLAGS} -Ilibft -Iprintf -c $? -o $@

${NAME}:	 server client

server:		server.o
		@make -C libft
		@make -C printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o server

client:		client.o
		@make -C libft
		@make -C printf
		${CC} ${CFLAGS} $? -Llibft -lft -Lprintf -lftprintf -o client

libft:
		make -C libft

printf:
		make -C printf

clean:
			make clean -C libft
			make clean -C printf
			${RM} ${OBJS}

fclean:		clean
			${RM} server client

re:			fclean all

.PHONY:		libft printf all clean fclean re
