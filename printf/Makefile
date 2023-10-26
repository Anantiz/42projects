CC=cc
AR=ar
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)
HEADERS=headers/

OBJ_DIR= obj

PRINTF=libprintf.a
LIBFT=libft.a
TEST=test

EXE= $(TEST)
LIBS_NAME=$(PRINTF) $(LIBFT)
LIBS := $(patsubst lib%.a,%, $(LIBS_NAME))

PRINTF_FILES=ft_printf.c \
			convert.c

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

TEST_FILES=test.c


###
# OBJECTS ---------------------------------------
###

LIBFT_OBJECTS := $(patsubst %.c,$(OBJ_DIR)/%.o,$(LIBFT_FILES))

$(OBJ_DIR):
	mkdir -p $@

$(OBJ_DIR)/%.o:%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -v -c $< -o $@



###
# MAIN TARGET -----------------------------------
###

all:$(PRINTF) $(TEST)

$(PRINTF):$(LIBFT) $(PRINTF_OBJECTS)
	@echo PRINTF
	$(AR) rcs $@ $>

###
# LIBS ------------------------------------------
###

$(LIBFT): $(LIBFT_OBJECTS)
	$(info Compiling $< to $@)
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

