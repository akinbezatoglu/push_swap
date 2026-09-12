# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/05 18:36:29 by abezatog          #+#    #+#              #
#    Updated: 2026/09/12 14:43:27 by abezatog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNSNAME = checker

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

COMMONSRCS = ft_ctxnew.c ft_ctxclear.c ft_parser.c \
			 ft_operations_core.c ft_swap_operations.c \
			 ft_push_operations.c ft_rotate_operations.c \
			 ft_reverse_rotate_operations.c ft_compute_disorder.c
COMMONOBJS = $(COMMONSRCS:.c=.o)

BNSSRCS = checker_bonus.c
BNSOBJS = $(BNSSRCS:.c=.o)

all: $(NAME)

bonus : $(BNSNAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS) $(COMMONOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(COMMONOBJS) $(LIBFT) -o $(NAME)

$(BNSNAME): $(LIBFT) $(BNSOBJS) $(COMMONOBJS)
	$(CC) $(CFLAGS) $(BNSOBJS) $(COMMONOBJS) $(LIBFT) -o $(BNSNAME)

clean:
	$(RM) $(OBJS) $(COMMONOBJS) $(BNSOBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BNSNAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re