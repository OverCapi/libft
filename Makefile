# ============================================================
# Colors / Forme
# ============================================================
LIGHT_GRAY	= \033[2m
ORANGE		= \033[1;33m
DARK_GRAY	= \033[0;90m
RED			= \033[0;91m
GREEN		= \033[0;92m
YELLOW		= \033[0;93m
BLUE		= \033[0;94m
MAGENTA		= \033[0;95m
CYAN		= \033[0;96m
WHITE		= \033[0;97m
RESET		= \033[0m

BOLD		= \033[1m
ITALIC		= \033[3m
UNDERLINE	= \033[4m
CROSS		= \033[9m
FLASH		= \033[5m
NEGATIF		= \033[7m

BAR			= "=========="

# ============================================================
# Project configurations
# ============================================================

NAME	= libft.a
SO_NAME	= libft.so

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3
AR		= ar -rcs

ECHO	= echo

# ============================================================
# Directories
# ============================================================

INCLUDES_DIR	= includes
SRC_DIR			= src

BUILD_DIR	= build
OBJ_DIR		= $(BUILD_DIR)/obj

# ============================================================
# Includes
# ============================================================

INCLUDES	= -I $(INCLUDES_DIR)

# ============================================================
# Sources — Char
# ============================================================

SRC_CHAR_DIR	= $(SRC_DIR)/char
SRC_CHAR		= \
	$(SRC_CHAR_DIR)/ft_iswhite_space.c \
	$(SRC_CHAR_DIR)/ft_isalnum.c \
	$(SRC_CHAR_DIR)/ft_isalpha.c \
	$(SRC_CHAR_DIR)/ft_isascii.c \
	$(SRC_CHAR_DIR)/ft_isdigit.c \
	$(SRC_CHAR_DIR)/ft_isprint.c \
	$(SRC_CHAR_DIR)/ft_tolower.c \
	$(SRC_CHAR_DIR)/ft_toupper.c

# ============================================================
# Sources — Memory
# ============================================================

SRC_MEM_DIR		= $(SRC_DIR)/mem
SRC_MEM			= \
	$(SRC_MEM_DIR)/ft_bzero.c \
	$(SRC_MEM_DIR)/ft_calloc.c \
	$(SRC_MEM_DIR)/ft_memchr.c \
	$(SRC_MEM_DIR)/ft_memcmp.c \
	$(SRC_MEM_DIR)/ft_memcpy.c \
	$(SRC_MEM_DIR)/ft_memmove.c \
	$(SRC_MEM_DIR)/ft_memset.c

# ============================================================
# Sources — String
# ============================================================

SRC_STR_DIR		= $(SRC_DIR)/str
SRC_STR			= \
	$(SRC_STR_DIR)/ft_split.c \
	$(SRC_STR_DIR)/ft_strchr.c \
	$(SRC_STR_DIR)/ft_strdup.c \
	$(SRC_STR_DIR)/ft_striteri.c \
	$(SRC_STR_DIR)/ft_strjoin.c \
	$(SRC_STR_DIR)/ft_strlcat.c \
	$(SRC_STR_DIR)/ft_strlcpy.c \
	$(SRC_STR_DIR)/ft_strlen.c \
	$(SRC_STR_DIR)/ft_strmapi.c \
	$(SRC_STR_DIR)/ft_strncmp.c \
	$(SRC_STR_DIR)/ft_strnstr.c \
	$(SRC_STR_DIR)/ft_strrchr.c \
	$(SRC_STR_DIR)/ft_strtrim.c \
	$(SRC_STR_DIR)/ft_substr.c

# ============================================================
# Sources — Converter
# ============================================================

SRC_CONVERTER_DIR	= $(SRC_DIR)/converter
SRC_CONVERTER		= \
	$(SRC_CONVERTER_DIR)/ft_atoi_safe.c \
	$(SRC_CONVERTER_DIR)/ft_atoi.c \
	$(SRC_CONVERTER_DIR)/ft_itoa.c

# ============================================================
# Sources — Write
# ============================================================

SRC_WRITE_DIR	= $(SRC_DIR)/write
SRC_WRITE		= \
	$(SRC_WRITE_DIR)/ft_putchar_fd.c \
	$(SRC_WRITE_DIR)/ft_putendl_fd.c \
	$(SRC_WRITE_DIR)/ft_putnbr_fd.c \
	$(SRC_WRITE_DIR)/ft_putstr_fd.c

# ============================================================
# Sources — Linked list
# ============================================================

SRC_LINKED_LIST_DIR	= $(SRC_DIR)/linked_list
SRC_LINKED_LIST		= \
	$(SRC_LINKED_LIST_DIR)/ft_lstnew.c \
	$(SRC_LINKED_LIST_DIR)/ft_lstadd_front.c \
	$(SRC_LINKED_LIST_DIR)/ft_lstsize.c \
	$(SRC_LINKED_LIST_DIR)/ft_lstlast.c \
	$(SRC_LINKED_LIST_DIR)/ft_lstadd_back.c \
	$(SRC_LINKED_LIST_DIR)/ft_lstdelone.c \
	$(SRC_LINKED_LIST_DIR)/ft_lstclear.c \
	$(SRC_LINKED_LIST_DIR)/ft_lstiter.c \
	$(SRC_LINKED_LIST_DIR)/ft_lstmap.c

# ============================================================
# Sources — Vector
# ============================================================

SRC_VECTOR_DIR	= $(SRC_DIR)/vector
SRC_VECTOR		= \
	$(SRC_VECTOR_DIR)/ft_vector_new.c \
	$(SRC_VECTOR_DIR)/ft_vector_reserve.c \
	$(SRC_VECTOR_DIR)/ft_vector_free.c \
	$(SRC_VECTOR_DIR)/ft_vector_add.c \
	$(SRC_VECTOR_DIR)/ft_vector_rm.c \
	$(SRC_VECTOR_DIR)/ft_vector_insert.c \
	$(SRC_VECTOR_DIR)/ft_vector_get.c

# ============================================================
# Sources — ft_printf
# ============================================================

SRC_FT_PRINTF_DIR	= $(SRC_DIR)/ft_printf
SRC_FT_PRINTF		= \
	$(SRC_FT_PRINTF_DIR)/converter.c \
	$(SRC_FT_PRINTF_DIR)/converter_utils.c \
	$(SRC_FT_PRINTF_DIR)/ft_printf.c

# ============================================================
# Sources — Get next line
# ============================================================

SRC_GNL_DIR		= $(SRC_DIR)/gnl
SRC_GNL			= \
	$(SRC_GNL_DIR)/get_next_line.c \
	$(SRC_GNL_DIR)/get_next_line_utils.c

# ============================================================
# Sources — Exit
# ============================================================

SRC_EXIT_DIR	= $(SRC_DIR)/exit
SRC_EXIT		= \
	$(SRC_EXIT_DIR)/exit_error.c \
	$(SRC_EXIT_DIR)/exit_free.c

# ============================================================
# Sources — All
# ============================================================

SRC		= \
	$(SRC_CHAR) \
	$(SRC_MEM) \
	$(SRC_STR) \
	$(SRC_CONVERTER) \
	$(SRC_WRITE) \
	$(SRC_FT_PRINTF) \
	$(SRC_GNL) \
	$(SRC_LINKED_LIST) \
	$(SRC_VECTOR) \
	$(SRC_EXIT)

SRC_OBJ = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC))

# ============================================================
# All objects
# ============================================================

OBJ		= $(SRC_OBJ)
DEPS	= $(OBJ:.o=.d)

# ============================================================
# Rules
# ============================================================

.PHONY: all so clean fclean re clean_header

all: $(NAME)

re: fclean all

$(NAME): $(OBJ)
	@$(ECHO) ""
	@$(ECHO) "$(BOLD)$(CYAN)$(BAR) $(NAME) creation $(BAR)$(RESET)"
	@$(AR) $(NAME) $(OBJ)
	@$(ECHO) "$(GREEN)$(NAME) created!$(RESET)"

so: $(SO_NAME)

$(SO_NAME): $(OBJ)
	@$(ECHO) ""
	@$(ECHO) "$(BOLD)$(CYAN)$(BAR) $(SO_NAME) creation $(BAR)$(RESET)"
	@$(CC) -shared -o $@ $(OBJ)
	@$(ECHO) "$(GREEN)$(SO_NAME) created!$(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(ECHO) "$(YELLOW)Compiling $<...$(RESET)"
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean: clean_header
	@rm -rf $(BUILD_DIR)
	@$(ECHO) "$(RED)Object files cleaned $(RESET)"

fclean: clean
	@rm -f $(NAME) $(SO_NAME)
	@$(ECHO) "$(RED)$(NAME) and $(SO_NAME) removed $(RESET)"

clean_header:
	@$(ECHO) ""
	@$(ECHO) "$(BOLD)$(CYAN)$(BAR) Cleaning $(BAR)$(RESET)"
