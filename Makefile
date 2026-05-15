# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fananrak <fananrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/02 22:15:14 by tsirakot          #+#    #+#              #
#    Updated: 2026/05/15 14:03:17 by fananrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME    = push_swap
CC      = cc
CFLAGS  = -Wall -Wextra -Werror
SRCS    = src/main.c \
          src/parsing.c \
          src/bench.c \
          src/disorder.c \
          utils/parsing_utils.c \
          utils/stack_utils.c \
          utils/find_max_min.c \
          operations/op_swap.c \
          operations/op_push.c \
          operations/op_rotate.c \
          operations/op_rev_rotate.c \
          flags/get_flags.c \
          Errors/free_errors.c \
          algorithms/simple.c \
          algorithms/medium.c \
          algorithms/raddix_sort.c \
          algorithms/adaptive.c
OBJS    = $(SRCS:.c=.o)
LIBFT   = libft/libft.a

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re debug