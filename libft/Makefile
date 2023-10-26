# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 06:06:39 by aurban            #+#    #+#              #
#    Updated: 2023/10/26 19:32:50 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC=gcc
AR=ar
CFLAGS=-Wall -Werror -Wextra

LIBFT_TARGET_NAME=libft.a

LIBFT_OBJ_DIR=libft_obj

LIBFT_FILES=ft_isascii.c \
	ft_memmove.c \
	ft_strlcat.c \
	ft_strtrim.c \
	ft_atoi.c \
	ft_isdigit.c \
	ft_memset.c \
	ft_strlcpy.c \
	ft_substr.c \
	ft_bzero.c \
	ft_isprint.c \
	ft_split.c \
	ft_strlen.c \
	ft_tolower.c \
	ft_calloc.c \
	ft_memchr.c \
	ft_strchr.c \
	ft_strncmp.c \
	ft_toupper.c \
	ft_isalnum.c \
	ft_memcmp.c \
	ft_strdup.c \
	ft_strnstr.c \
	ft_isalpha.c \
	ft_memcpy.c \
	ft_strjoin.c \
	ft_strrchr.c \
	ft_itoa.c \
	ft_strmapi.c \
	ft_striteri.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c

LIBFT_FILES_BONUSES=ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c

LIBFT_OBJECTS = $(patsubst %.c,%.o,$(LIBFT_FILES))
LIBFT_OBJECTS_BONUSES = $(patsubst %.c,%.o,$(LIBFT_FILES_BONUSES))

$(LIBFT_OBJ_DIR):
	@echo Created $@
	@mkdir -p $@

%.o:%.c | $(LIBFT_OBJ_DIR)
	echo $@
	$(CC) $(CFLAGS) -c $<
	mv $@ -t $(addprefix $(LIBFT_OBJ_DIR)/,$@)

all: $(LIBFT_OBJ_DIR) $(LIBFT_TARGET_NAME)

$(LIBFT_TARGET_NAME): $(LIBFT_OBJECTS)
	@echo Packing default files into Archive
	$(AR) rcs $@ $(addprefix $(LIBFT_OBJ_DIR)/,$^)

bonus: $(LIBFT_OBJECTS_BONUSES)
	@echo Packing basic files into archive
	$(AR) rcs $@ $(LIBFT_OBJ_DIR)/$^

clean: 
	rm -rf $(LIBFT_OBJ_DIR)

fclean: clean
	rm -rf $(LIBFT_TARGET_NAME)

re: fclean all

.PHONY: all bonus clean fclean re