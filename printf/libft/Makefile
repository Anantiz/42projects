# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aurban <aurban@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/20 06:06:39 by aurban            #+#    #+#              #
#    Updated: 2023/10/29 02:59:39 by aurban           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(origin NAME), undefined)
    NAME:=libft.a
	LIB_FT_PATH:=.
else
	TARGETS+=libft.a
endif


LIB_FT_FILES:=ft_atoi.c \
	ft_bzero.c \
	ft_calloc.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_itoa.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_putstr_fd.c \
	ft_split.c \
	ft_strchr.c \
	ft_strdup.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strmapi.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strtrim.c \
	ft_substr.c \
	ft_tolower.c \
	ft_toupper.c \
	ft_isascii.c \
	ft_lstnew.c \
	ft_lstadd_front.c \
	ft_lstsize.c \
	ft_lstlast.c \
	ft_lstadd_back.c \
	ft_lstdelone.c \
	ft_lstclear.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_uitoa.c \
	ft_strappendmax.c

LIB_FT_FILES:= $(addprefix $(LIB_FT_PATH)/,$(LIB_FT_FILES))
LIB_FT_OBJECTS:= $(patsubst %.c,%.o,$(LIB_FT_FILES))

ifeq ($(origin OBJECTS), file)
	OBJECTS+=$(LIB_FT_OBJECTS)
else
all:$(NAME)
	@echo libft all

$(NAME): $(LIB_FT_OBJECTS)
	@echo compiling libft
	@$(AR) rcs $@ $^

clean: 
	@$(RM) $(LIB_FT_OBJECTS)

fclean: clean
	@$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

endif