CC=cc
AR=ar
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)

HEADERS=headers/
PRINTF=libprintf.a
LIBFT=libft.a
TEST=test
EXE= $(TEST)
OBJ=$(LIBFT_OBJECTS) $(PRINTF_OBJECTS) $(TEST_OBJECTS)
LIBS := $(patsubst lib%.a,%,$(PRINTF) $(LIBFT))

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

PRINTF_FILES =	src/ft_printf.c \
				src/convert.c \
TEST_FILES= test.c

###
# OBJECTS ---------------------------------------
###

LIBFT_OBJECTS=$(LIBFT_FILES:.c=.o)
PRINTF_OBJECTS=$(PRINTF_FILES:.c=.o)
TEST_OBJECTS=$(TEST_FILES:.c=.o)

###
# MAIN TARGET -----------------------------------
###

all:$(PRINTF) $(TEST)

$(PRINTF): $(PRINTF_OBJECTS)
	@echo PRINTF
	$(AR) rcs $@ $^

$(PRINTF_OBJECTS): $(LIBFT)

###
# LIBS ------------------------------------------
###

$(LIBFT): $(LIBFT_OBJECTS)
	@echo LIBFT
	$(AR) rcs $@ $^

$(LIBFT_OBJECTS): $(LIBFT_FILES)

###
# TEST ------------------------------------------
###

$(TEST): $(PRINTF) $(TEST_OBJECTS)
	@echo test
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -L. $(addprefix -l, $(LIBS)) -o $@

$(TEST_OBJECTS): $(TEST_FILES)

###
# Utilities -------------------------------------
###

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXE) $(LIBS)

re: fclean all
	
.PHONY:clean fclean re

