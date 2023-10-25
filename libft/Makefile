# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 06:06:39 by aurban            #+#    #+#              #
#    Updated: 2023/10/24 16:18:48 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
CFLAGS=-Wall -Werror -Wextra
NAME=libft.a

FILES=ft_isascii.c ft_memmove.c ft_strlcat.c ft_strtrim.c ft_atoi.c \
	ft_isdigit.c ft_memset.c ft_strlcpy.c ft_substr.c ft_bzero.c \
	ft_isprint.c ft_split.c ft_strlen.c ft_tolower.c ft_calloc.c \
	ft_memchr.c ft_strchr.c ft_strncmp.c ft_toupper.c ft_isalnum.c \
	ft_memcmp.c ft_strdup.c ft_strnstr.c ft_isalpha.c ft_memcpy.c \
	ft_strjoin.c ft_strrchr.c ft_itoa.c ft_strmapi.c ft_striteri.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c $(BONUSES)

BONUSES=ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

# @ means the target/rule name; ^ means the last elem of the rule dependency
$(NAME): $(OBJECTS)
	$(AR) rcs $@ $^

clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all

bonus: all

.PHONY: clean fclean