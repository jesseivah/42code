# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jebitrus <jebitrus@student.42berlin.d      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 21:01:23 by jebitrus          #+#    #+#              #
#    Updated: 2024/01/24 21:01:45 by jebitrus         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
LIBFT = libft.a
PRINTF = libftprintf.a
CFLAGS = -Wall -Werror -Wextra

# Source files for push_swap
SRCS_PUSH_SWAP = push_swap.c main.c stack_utils.c moves.c double_moves.c debug_utils.c basic_sort.c normalize.c radix_sort.c

# Object files for push_swap
OBJS_PUSH_SWAP = $(SRCS_PUSH_SWAP:.c=.o)

# Include path for printf project
PRINTF_INCLUDE = -Iprintf

all: $(NAME)

$(NAME): $(LIBFT) $(PRINTF) $(OBJS_PUSH_SWAP)
	@cc $(CFLAGS) $(OBJS_PUSH_SWAP) -L. -lftprintf $(LIBFT) -o $(NAME)
	@echo "...push_swap compiled."

$(LIBFT): libft/$(LIBFT)
	@cp libft/$(LIBFT) $(LIBFT)
	@echo "...libft.a copied to current directory."

libft/$(LIBFT):
	@$(MAKE) -C ./libft

$(PRINTF): printf/$(PRINTF)
	@cp printf/$(PRINTF) $(PRINTF)
	@echo "...libftprintf.a copied to current directory."

printf/$(PRINTF):
	@$(MAKE) -C ./printf

%.o: %.c
	@cc $(CFLAGS) $(PRINTF_INCLUDE) -c $< -o $@

clean:
	@$(MAKE) clean -C ./libft
	@$(MAKE) clean -C ./printf
	@rm -f $(OBJS_PUSH_SWAP) $(DEPS_PUSH_SWAP)
	@echo "...object files cleaned."

fclean: clean
	@$(MAKE) fclean -C ./libft
	@$(MAKE) fclean -C ./printf
	@rm -f $(NAME) $(LIBFT) $(PRINTF)
	@echo "...push_swap program and libraries cleaned."

re: fclean all

.PHONY: all fclean re clean libft
