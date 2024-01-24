# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebitrus <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/06 00:29:38 by jebitrus          #+#    #+#              #
#    Updated: 2023/06/06 00:29:53 by jebitrus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a
HEADER = libft.h
CC = cc
SRCS = ft_atoi.c \
		ft_bzero.c \
		ft_calloc.c \
		ft_isalnum.c \
		ft_isalpha.c \
		ft_isascii.c \
		ft_isdigit.c \
		ft_isprint.c \
		ft_itoa.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_memcpy.c \
		ft_memmove.c \
		ft_memset.c \
		ft_putchar_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_putstr_fd.c \
		ft_split.c \
		ft_strchr.c \
		ft_strdup.c \
		ft_striteri.c \
		ft_strjoin.c \
		ft_strlcat.c \
		ft_strlcpy.c \
		ft_strlen.c \
		ft_strmapi.c \
		ft_strncmp.c \
		ft_strnstr.c \
		ft_strrchr.c \
		ft_strtrim.c \
		ft_substr.c \
		ft_tolower.c \
		ft_toupper.c
BONUS_SRCS = ft_lstnew.c \
	     	ft_lstadd_front.c \
	     	ft_lstsize.c \
	     	ft_lstlast.c \
	     	ft_lstadd_back.c \
	     	ft_lstdelone.c \
	     	ft_lstclear.c \
	     	ft_lstiter.c \
	     	ft_lstmap.c 
OBJS = $(SRCS:.c=.o)
BONUS = $(BONUS_SRCS:.c=.o)
FLAGS = -Wall -Wextra -Werror -I.$(HEADER)
AR = ar -rcs

all: $(NAME)

$(NAME): $(OBJS) $(HEADER) $(BONUS)
	$(AR) $(NAME) $(OBJS) $(HEADER)
	
bonus:		$(NAME) $(BONUS)
			ar -rcs $(NAME) $(BONUS)


%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean all bonus

.PHONY: all clean fclean re bonus
