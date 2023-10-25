CC=cc
AR=ar
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)
PRINTF=libprintf.a
TEST=test
HEADERS=headers/
LIBFT=libft.a

PRINTF_FILES =	src/ft_printf.c \
				src/convert.c \

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
				ft_lstmap.c 


###
# MAIN TARGET -----------------------------------
###
all:$(PRINTF) $(TEST)

$(PRINTF): PRINTF_OBJECTS
	@echo PRINTF
	$(AR) rcs $@ $^

PRINTF_OBJECTS: $(LIBFT) $(PRINTF_FILES)
	@echo PRINTF_OBJECTS
	$(CC) $(CFLAGS) -v -c $>

###
# LIBS ------------------------------------------
###

$(LIBFT): LIBFT_OBJECTS
	@echo LIBFT
	$(AR) rcs $@ $^

LIBFT_OBJECTS: $(LIBFT_FILES)
	@echo Libft OBJECTS
	$(CC) $(CFLAGS) -v -c $>

###
# TEST ------------------------------------------
###

$(TEST): $(PRINTF)
	@echo test
	$(CC) $(CFLAGS) test.c -L. -l$(PRINTF) -o $@

###
# Utilities -------------------------------------
###

clean:
	rm -rf $(PRINTF_OBJECTS)

fclean: clean
	rm -rf $(PRINTF) $(TEST)

re: fclean all
	
.PHONY:clean fclean re

