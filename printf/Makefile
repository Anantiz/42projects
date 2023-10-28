# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/28 09:40:57 by aurban            #+#    #+#              #
#    Updated: 2023/10/28 16:36:59 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=cc
CFLAGS=-Wall -Werror -Wextra
RM=rm -rf

NAME=libftprintf.a
OBJECTS=

LIB_FT_PATH=libft
LIB__FT_PRINTF_PATH=libftprintf

TARGETS=

include $(addsuffix /Makefile,$(LIB_FT_PATH) $(LIB__FT_PRINTF_PATH))

all: $(NAME)

$(NAME): $(OBJECTS)
	@echo Archiving $(TARGETS) into $(NAME)
	@$(AR) rcs $@ $^
	@echo Archiving done

clean: 
	@$(RM) $(OBJECTS)

fclean: clean
	@$(RM) $(NAME) $(TARGETS)
re: fclean all