CC=cc
AR=ar
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)
NAME=libprintf.a
HEADERS=headers/
TEST=test

OBJECTS = $(FILES:.c=.o)

OBJECTS_BONUS= $(FILES_BONUS:.c=.o)

LIBFT_OBJECT=$(LIBFT_FILES:.c=.o)

###
# Defaults --------------------------------------
###

all: $(NAME)
	$(TEST)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

$(OBJECTS): $(LIBFT)

$(NAME): $(OBJECTS)
	$(AR) rcs $@ $^

###
# Libs and Bonus --------------------------------
###

$(LIBFT): $(LIBFT_OBJECT)
	$(AR) rcs $@ $^

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	$(AR) rcs $@ $^

###
# TEST ------------------------------------------
###

$(TEST): $(NAME) $(OBJECTS_TEST)
	$(CC) $(CFLAGS) -l $(NAME)

$(TEST)_bonus: bonus $(OBJECTS_TEST)
	$(CC) $(CFLAGS) -l $(NAME)

test.o: test.c
	$(CC) $(CFLAGS) -c $< -o $@

###
# Utilities -------------------------------------
###

clean:
	rm -rf $(OBJECTS)

fclean: clean
	rm -rf $(NAME) $(TEST)

re: fclean all
	
.PHONY:clean fclean re

FILES =	ft_printf.c \
		convert.c \

FILES_BONUS=

LIBFT_FILES =	ft_isascii.c \
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
				ft_putnbr_fd.c \
				ft_lstnew.c \
				ft_lstadd_front.c \
				ft_lstsize.c \
				ft_lstlast.c \
				ft_lstadd_back.c \
				ft_lstdelone.c \
				ft_lstclear.c \
				ft_lstiter.c \
				ft_lstmap.c \
