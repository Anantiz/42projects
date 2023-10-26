CC=cc
AR=ar
CFLAGS=-Wall -Wextra -Werror -I$(HEADERS)
HEADERS=headers/

PRINTF=libprintf.a
LIBFT=libft.a
TEST=test

OBJ_DIR= obj
LIBS_OBJ_FOLDER_NAME=printf libft 
LIBS_TARGET_NAME=libprintf.a libft.a

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
LIBFT_FILES := $(addprefix libft/,$(LIBFT_FILES))
LIBFT_OBJECTS := $(patsubst %.c,%.o,$(LIBFT_FILES))

PRINTF_FILES := $(addprefix printf/,$(PRINTF_FILES))
PRINTF_OBJECTS := $(patsubst %.c,%.o,$(PRINTF_FILES))

$(OBJ_DIR): $(LIBS_OBJ_FOLDER_NAME)
	mkdir -p $@
	$(foreach lib,$^, mkdir -p $@/$(lib))

%.o: %.c | $(OBJ_DIR)
	$(info Compiling $< to $@)
	$(CC) $(CFLAGS) -c $< -o $@
	mv $@ -t$(OBJ_DIR)/$(dir $@)


###
# MAIN TARGET -----------------------------------
###

all:$(PRINTF) $(TEST)

$(PRINTF):$(LIBFT) $(PRINTF_OBJECTS)
	$(info Compiling $< to $@)
	$(AR) rcs $@ obj/$2
	echo PRINTF

###
# LIBS ------------------------------------------
###

$(LIBFT): $(LIBFT_OBJECTS)
	$(info Compiling $< to $@)
	$(AR) rcs $@ $(OBJ_DIR)/$<

###
# TEST ------------------------------------------
###

LIBS := $(patsubst lib%.a,%, $(LIBS_TARGET_NAME))
$(TEST): $(PRINTF) $(TEST_OBJECTS)
	@echo test
	$(CC) $(CFLAGS) $(TEST_OBJECTS) -L. $(addprefix -l, $(LIBS)) -o $@

###
# Utilities -------------------------------------
###

clean:
	rm -rf $(OBJ_DIR) 

fclean: clean
	rm -rf $(TEST) $(LIBS_TARGET_NAME)

re: fclean all
	
.PHONY:clean fclean re obj

