# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/12 16:43:24 by aurban            #+#    #+#              #
#    Updated: 2023/11/13 16:28:25 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC:=cc
INCLUDE_PATH=./includes
CFLAGS:=-I$(INCLUDE_PATH) #-Wall -Werror -Wextra
RM:=rm -rf

NAME:=fractol
LIBS:=libft.a libmlx.a

SRC_PATH:=src
MINILIBX_PATH:=minilibx-linux
LIBFT_PATH:=libft

SRC_FILES:= renderer.c \
	generator.c

SRC_FILES:= $(addprefix $(SRC_PATH)/,$(SRC_FILES))
SRC_FILES+= main.c
SRC_OBJECTS:= $(patsubst %.c,%.o,$(SRC_FILES))

all: $(NAME)

$(LIBS):
	@make -C $(LIBFT_PATH)/ all
	@make -C $(LIBFT_PATH)/ clean
	@mv $(LIBFT_PATH)/libft.a ./
	@make -C $(MINILIBX_PATH)/ all
	@make -C $(MINILIBX_PATH)/ clean
	@mv $(MINILIBX_PATH)/libmlx.a ./

$(NAME): $(SRC_OBJECTS) | $(LIBS)
	$(CC) $(CFLAGS) $^ $(LIBS) -o $@
	
clean: 
	@$(RM) $(SRC_OBJECTS)

fclean: clean
	@$(RM) $(NAME) $(LIBS)

re: fclean all

.PHONY: all clean fclean re
