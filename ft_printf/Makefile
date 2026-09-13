# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/27 18:47:39 by abezatog          #+#    #+#              #
#    Updated: 2026/09/14 00:45:26 by abezatog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a

CFLAGS = -Wall -Wextra -Werror

MANDATORY_SRCS = ft_printf.c
MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)

BNSSRCS = ft_printf_bonus.c ft_putnstr_bonus.c ft_flags_parse_bonus.c \
		  ft_flags_override_bonus.c ft_flags_new_bonus.c \
		  ft_flags_print_char_bonus.c ft_flags_print_str_bonus.c \
		  ft_flags_print_nbr_bonus.c ft_flags_print_nbr_u_bonus.c \
		  ft_flags_print_ptr_bonus.c ft_flags_print_hex_bonus.c \
		  ft_put_padding_bonus.c ft_count_digit_bonus.c
BNSOBJS = $(BNSSRCS:.c=.o)

COMMON_SRCS = ft_putchar.c ft_putstr.c ft_puthex.c ft_putptr.c \
			  ft_putnbr.c ft_putnbr_unsigned.c
COMMON_OBJS = $(COMMON_SRCS:.c=.o)

all: $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(COMMON_OBJS) $(MANDATORY_OBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(COMMON_OBJS) $(MANDATORY_OBJS)

bonus: $(LIBFT) $(COMMON_OBJS) $(BNSOBJS)
	cp $(LIBFT) $(NAME)
	ar rcs $(NAME) $(COMMON_OBJS) $(BNSOBJS)

clean:
	$(RM) $(COMMON_OBJS) $(MANDATORY_OBJS) $(BNSOBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re