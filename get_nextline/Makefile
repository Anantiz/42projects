# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/29 16:08:52 by aurban            #+#    #+#              #
#    Updated: 2023/10/29 16:32:57 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS= -Wall -Wextra -Werror -D BUFFER_SIZE=32
AR=ar
RM=rm -rf

NAME=get_next_line

NEXT_LINE_FILES:=get_next_line.c\
	get_next_line_utils.c\

NEXT_LINE_OBJECTS= $(patsubst %.c,%.o, $(NEXT_LINE_FILES))

all: $(NAME)

$(NAME): $(NEXT_LINE_OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	$(RM) $(NEXT_LINE_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re