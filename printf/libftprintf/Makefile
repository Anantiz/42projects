# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/27 14:49:11 by aurban            #+#    #+#              #
#    Updated: 2023/10/29 05:38:48 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(origin NAME), undefined)
	NAME:=libftprintf.a
	LIB_FT_PRINTF_PATH:=.
else
	TARGETS+=libftprintf.a
endif

LIB__FT_PRINTF_FILES:=ft_printf.c\
	ft_uitohex.c \
	ft_ltohex.c \
	ft_ultohex.c \
	ft_send_to_buffer.c \
	ft_arg_to_buffer.c
	
LIB__FT_PRINTF_FILES:= $(addprefix $(LIB__FT_PRINTF_PATH)/,$(LIB__FT_PRINTF_FILES))
LIB__FT_PRINTF_OBJECTS:=$(patsubst %.c,%.o,$(LIB__FT_PRINTF_FILES))

ifeq ($(origin OBJECTS), file)
	OBJECTS+=$(LIB__FT_PRINTF_OBJECTS)
else
all: $(NAME)

$(NAME): $(LIB__FT_PRINTF_OBJECTS)
	@echo compiling printf
	@$(AR) rcs $@ $^

clean:
	@$(RM) $(LIB__FT_PRINTF_OBJECTS)

fclean: clean
	@$(RM) $(NAME)
	
re: fclean all

.PHONY: all clean fclean re bonus
endif