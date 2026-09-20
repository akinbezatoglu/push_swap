# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yturkeri <yturkeri@student.42istanbul.com.tr>+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/09/05 18:36:29 by abezatog          #+#    #+#              #
#    Updated: 2026/09/20 18:54:21 by yturkeri         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
BNSNAME = checker

LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

FT_PRINTF_DIR = ./ft_printf
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a

CFLAGS = -Wall -Wextra -Werror

SRCS = push_swap.c
OBJS = $(SRCS:.c=.o)

COMMONSRCS = ft_ctxnew.c ft_ctxclear.c ft_parser.c ft_parser_utils.c \
			 ft_operations_core.c ft_operations_swap.c \
			 ft_operations_push.c ft_operations_rotate.c \
			 ft_operations_reverse_rotate.c ft_compute_disorder.c \
			 ft_sort.c ft_sort_simple_algorithm.c ft_sort_medium_algorithm.c \
			 ft_sort_complex_algorithm.c ft_sort_utils.c
COMMONOBJS = $(COMMONSRCS:.c=.o)

BNSSRCS = checker_bonus.c checker_gnl_bonus.c
BNSOBJS = $(BNSSRCS:.c=.o)

all: $(NAME)

bonus : $(BNSNAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(FT_PRINTF):
	$(MAKE) -C $(FT_PRINTF_DIR)

$(NAME): $(LIBFT) $(FT_PRINTF) $(OBJS) $(COMMONOBJS)
	$(CC) $(CFLAGS) $(OBJS) $(COMMONOBJS) $(LIBFT) $(FT_PRINTF) -o $(NAME)

$(BNSNAME): $(LIBFT) $(FT_PRINTF) $(BNSOBJS) $(COMMONOBJS)
	$(CC) $(CFLAGS) $(BNSOBJS) $(COMMONOBJS) $(LIBFT) $(FT_PRINTF) -o $(BNSNAME)

clean:
	$(RM) $(OBJS) $(COMMONOBJS) $(BNSOBJS)
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	$(RM) $(NAME) $(BNSNAME)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re