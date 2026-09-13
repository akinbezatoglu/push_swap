# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abezatog <abezatog@student.42istanbul.c    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/08/05 11:15:16 by abezatog          #+#    #+#              #
#    Updated: 2026/09/13 11:04:20 by abezatog         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

CFLAGS = -Wall -Wextra -Werror

SRCS = ft_isdigit.c ft_strncmp.c ft_atoi.c \
	   ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	   ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \
	   ft_lstmap.c ft_strlen.c ft_strchr.c ft_strlcpy.c ft_split.c
OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re