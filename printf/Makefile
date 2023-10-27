# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 14:49:11 by aurban            #+#    #+#              #
#    Updated: 2023/10/27 16:06:26 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

AR=ar
CC=cc
CFLAGS=-Wall -Wextra -Werror -Iincludes

RM=rm -rf

NAME=libprintf.a
F_DIR:=libprintf

FILES=ft_printf.c

OBJECTS:=$(patsubst %.c,%.o,$(FILES))

all: $(NAME)

$(NAME): $(F_DIR)/$(OBJECTS)
	$(AR) rcs $@ $^

clean:
	@$(RM) $(OBJ_DIR)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
