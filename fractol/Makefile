# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 16:43:24 by aurban            #+#    #+#              #
#    Updated: 2023/11/12 16:53:26 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra
RM=rm -rf

NAME=fractol

LIBS=libft.a
LIB_OBJECTS=
LIB_FT_PATH=libft

TARGETS=

include $(addsuffix /Makefile,$(LIB_FT_PATH))

SRC_FILEs:= renderer.c \
	generator.c

SRC_FILES:= $(addprefix src/,$(SRC_FILES))
SRC_OBJECTS:= $(patsubst %.c,%.o,$(SRC_FILES))

all: $(NAME)

$(LIBS): $(LIB_OBJECTS)
	@echo Archiving $(TARGETS)
	@$(AR) rcs $@ $^
	@echo Archiving done

$(NAME): $(SRC_OBJECTS) | $(LIBS)

clean: 
	@$(RM) $(LIB_OBJECTS) $(SRC_OBJECTS)

fclean: clean
	@$(RM) $(NAME) $(TARGETS) $(LIBS)
