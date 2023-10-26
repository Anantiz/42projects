CC=cc
AR=ar
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)
HEADERS=headers/

OBJ_DIR:= obj

PRINTF=libprintf.a
LIBFT=libft.a
TEST=test

EXE= $(TEST)
LIBS_NAME=$(PRINTF) $(LIBFT)
LIBS := $(patsubst lib%.a,%, $(LIBS_NAME))

PRINTF_FILES=printf/ft_printf.c \
			printf/convert.c
LIBFT_FILES=libft/ft_isascii.c \
			libft/ft_memmove.c \
			libft/ft_strlcat.c \
			libft/ft_strtrim.c \
			libft/ft_atoi.c \
			libft/ft_isdigit.c \
			libft/ft_memset.c \
			libft/ft_strlcpy.c \
			libft/ft_substr.c \
			libft/ft_bzero.c \
			libft/ft_isprint.c \
			libft/ft_split.c \
			libft/ft_strlen.c \
			libft/ft_tolower.c \
			libft/ft_calloc.c \
			libft/ft_memchr.c \
			libft/ft_strchr.c \
			libft/ft_strncmp.c \
			libft/ft_toupper.c \
			libft/ft_isalnum.c \
			libft/ft_memcmp.c \
			libft/ft_strdup.c \
			libft/ft_strnstr.c \
			libft/ft_isalpha.c \
			libft/ft_memcpy.c \
			libft/ft_strjoin.c \
			libft/ft_strrchr.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_striteri.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_lstnew.c \
			libft/ft_lstadd_front.c \
			libft/ft_lstsize.c \
			libft/ft_lstlast.c \
			libft/ft_lstadd_back.c \
			libft/ft_lstdelone.c \
			libft/ft_lstclear.c \
			libft/ft_lstiter.c \
			libft/ft_lstmap.c

TEST_FILES=test.c


###
# OBJECTS ---------------------------------------
###

LIBFT_OBJECTS=$(patsubst libft/%.c, $(OBJ_DIR)/%.o, $(LIBFT_FILES))

PRINTF_OBJECTS=$(patsubst printf/%.c, $(OBJ_DIR)/%.o, $(PRINTF_FILES))

TEST_OBJECTS=$(patsubst %.c, $(OBJ_DIR)/%.o, $(TEST_FILES))

$(OBJ_DIR)/%.o:%.c
	$(info Compiling $< to $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $@

###
# MAIN TARGET -----------------------------------
###

all:$(OBJ_DIR) $(PRINTF) $(TEST)

$(PRINTF):$(LIBFT) $(PRINTF_OBJECTS)
	@echo PRINTF
	$(AR) rcs $@ $>

###
# LIBS ------------------------------------------
###

$(LIBFT): $(LIBFT_OBJECTS)
	@echo LIBFT
	$(AR) rcs $@ $<

###
# TEST ------------------------------------------
###

$(TEST): $(PRINTF) $(TEST_OBJECTS)
	@echo test
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -L. $(addprefix -l, $(LIBS)) -o $@

###
# Utilities -------------------------------------
###

clean:
	rm -rf $(OBJ_DIR) 

fclean: clean
	rm -rf $(EXE) $(LIBS_NAME)

re: fclean all
	
.PHONY:clean fclean re

