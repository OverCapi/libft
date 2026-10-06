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

# ============================================================
# Display helpers
# ============================================================

PRINT		= printf "%b\n"

# $(call HEADER,title) : framed title printed at the start of each step
BOX_LINE	= ──────────────────────────────────────────
HEADER		= printf "\n$(BOLD)$(CYAN)╭$(BOX_LINE)╮\n│$(RESET) $(BOLD)%-40s$(RESET) $(BOLD)$(CYAN)│\n╰$(BOX_LINE)╯$(RESET)\n" "$(1)"

# $(call PROGRESS,current,total,file) : redraws the progress display in place.
# It takes two lines : the bar, and below it the file being compiled.
# - Each update goes back up one line ("\033[1A") and rewrites both lines.
#   At the end, the file line is cleared and the cursor stays on it.
# - A line must never be wider than the terminal, otherwise it wraps and
#   the cursor no longer goes back to the right place. The width is read
#   from the terminal itself (/dev/tty), the bar shrinks (down to 10 cells)
#   and the file name is truncated on narrow terminals.
# - When the output is not a terminal (pipe, IDE output panel...), lines
#   cannot be rewritten: only the final, full bar is printed.
# BAR_FULL / BAR_EMPTY hold BAR_WIDTH characters of 3 bytes each; printf
# cuts them in bytes (LC_ALL=C) to draw the filled / empty parts.
BAR_WIDTH	= 30
BAR_FULL	= ██████████████████████████████
BAR_EMPTY	= ░░░░░░░░░░░░░░░░░░░░░░░░░░░░░░
BAR_INFO	= 16
PROGRESS	= cur=$(1); total=$(2); [ $$cur -gt $$total ] && total=$$cur; \
	if [ -t 1 ]; then tty=1; else tty=0; fi; \
	if [ $$tty -eq 1 ] || [ $$cur -eq $$total ]; then \
	cols=$$({ stty size < /dev/tty; } 2>/dev/null | cut -d " " -f 2); \
	[ -n "$$cols" ] && [ "$$cols" -gt 0 ] 2>/dev/null || cols=$$(tput cols 2>/dev/null); \
	[ -n "$$cols" ] || cols=80; \
	width=$$((cols - 1 - $(BAR_INFO))); \
	[ $$width -gt $(BAR_WIDTH) ] && width=$(BAR_WIDTH); \
	[ $$width -lt 10 ] && width=10; \
	name_max=$$((cols - 5)); [ $$name_max -lt 0 ] && name_max=0; \
	fill=$$((cur * width / total)); empty=$$((width - fill)); \
	[ $$tty -eq 1 ] && [ $$cur -gt 1 ] && printf "\033[1A"; \
	printf "\r\033[K$(GREEN)%s$(DARK_GRAY)%s$(RESET) %3d%% $(DARK_GRAY)[%d/%d]$(RESET)\n" \
		"$$(LC_ALL=C printf "%.$$((fill * 3))s" "$(BAR_FULL)")" \
		"$$(LC_ALL=C printf "%.$$((empty * 3))s" "$(BAR_EMPTY)")" \
		$$((cur * 100 / total)) $$cur $$total; \
	if [ $$cur -lt $$total ]; then \
		printf "\033[K$(DARK_GRAY)  ↳ %.$${name_max}s$(RESET)" "$(3)"; \
	else printf "\033[K"; fi; \
	fi; true

# ============================================================
# Project configurations
# ============================================================

NAME	= libft.a
SO_NAME	= libft.so

CC		= cc
CFLAGS	= -Wall -Werror -Wextra -g3
AR		= ar -rcs

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
	$(SRC_STR_DIR)/ft_substr.c \
	$(SRC_STR_DIR)/ft_strcmp.c \
	$(SRC_STR_DIR)/ft_free_split.c

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
	$(SRC_FT_PRINTF_DIR)/ft_printf.c \
	$(SRC_FT_PRINTF_DIR)/pf_parse.c \
	$(SRC_FT_PRINTF_DIR)/pf_convert.c \
	$(SRC_FT_PRINTF_DIR)/pf_output.c \
	$(SRC_FT_PRINTF_DIR)/pf_utils.c

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

SRC_OBJ = $(call OBJ_OF,$(SRC))

# ============================================================
# All objects
# ============================================================

OBJ		= $(SRC_OBJ)

# Objects missing or older than their source, i.e. those make will compile.
# Evaluated lazily by the first compilation, so the count is right even
# after the fclean of `make re`.
OBJ_OF		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(1))
OUTDATED	= $(shell $(foreach src,$(SRC),\
				{ [ ! -f $(call OBJ_OF,$(src)) ] \
				|| [ $(src) -nt $(call OBJ_OF,$(src)) ]; } && echo x;))
TOTAL		=
COMPILED	=

# ============================================================
# Rules
# ============================================================

.PHONY: all so clean fclean re

all: $(NAME)

re: fclean all

# ============================================================
# Step 1 — Compilation
# ============================================================

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(if $(TOTAL),,$(eval TOTAL := $(words $(OUTDATED))))
	$(eval COMPILED += x)
	@$(if $(filter 1,$(words $(COMPILED))),$(call HEADER,Compiling $(NAME)),true)
	@mkdir -p $(dir $@)
	@$(call PROGRESS,$(words $(COMPILED)),$(TOTAL),$(<:$(SRC_DIR)/%=%))
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@ || { printf "\n"; exit 1; }

# ============================================================
# Step 2 — Archive
# ============================================================

$(NAME): $(OBJ)
	@$(call HEADER,Creating $(NAME))
	@rm -f $(NAME)
	@$(AR) $(NAME) $(OBJ)
	@$(PRINT) "$(GREEN)✔ $(NAME) created$(RESET)"

# ============================================================
# Step 2 bis — Shared library (make so)
# ============================================================

so: $(SO_NAME)

$(SO_NAME): $(OBJ)
	@$(call HEADER,Creating $(SO_NAME))
	@$(CC) -shared -o $@ $(OBJ)
	@$(PRINT) "$(GREEN)✔ $(SO_NAME) created$(RESET)"

# ============================================================
# Cleaning
# ============================================================

clean:
	@$(call HEADER,Cleaning objects)
	@rm -rf $(BUILD_DIR)
	@$(PRINT) "$(RED)✘ $(BUILD_DIR)/ removed$(RESET)"

fclean: clean
	@$(call HEADER,Cleaning libraries)
	@rm -f $(NAME) $(SO_NAME)
	@$(PRINT) "$(RED)✘ $(NAME) and $(SO_NAME) removed$(RESET)"
