# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/16 18:56:37 by fananrak          #+#    #+#              #
#    Updated: 2026/05/16 19:57:45 by fananrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = src/push_swap/main.c \
          src/push_swap/parsing.c \
          src/bench/print_bench.c \
          src/disorder/disorder.c \
          src/utils/parsing_utils.c \
          src/utils/stack_utils.c \
          src/utils/find_max_min.c \
          src/operations/op_swap.c \
          src/operations/op_push.c \
          src/operations/op_rotate.c \
          src/operations/op_rev_rotate.c \
          src/flags/get_flags.c \
          src/Errors/free_errors.c \
          src/algorithms/simple.c \
          src/algorithms/medium.c \
          src/algorithms/radix_sort.c \
          src/algorithms/adaptative.c
OBJS    = $(SRCS:.c=.o)
LIBFT   = libft/libft.a
INCLUDES = -I src/includes -I libft

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) $(LIBFT) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
