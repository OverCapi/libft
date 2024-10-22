SRCS_FILE =  ./ft_isalnum.c \
			 ./ft_isalpha.c \
			 ./ft_isascii.c \
			 ./ft_isdigit.c \
			 ./ft_isprint.c \
			 ./ft_bzero.c \
			 ./ft_memcpy.c \
			 ./ft_memset.c \
			 ./ft_memmove.c \
			 ./ft_strlen.c \
			 ./ft_strlcpy.c \
			 ./ft_strlcat.c \
			 ./ft_toupper.c \
			 ./ft_tolower.c \
			 ./ft_strchr.c \
			 ./ft_strrchr.c \
			 ./ft_strncmp.c \
			 ./ft_memchr.c \
			 ./ft_memcmp.c \
			 ./ft_strnstr.c \
			 ./ft_atoi.c \
			 ./ft_calloc.c \
			 ./ft_strdup.c \
			 ./ft_substr.c \
			 ./ft_strjoin.c \
			 ./ft_strtrim.c \
			 ./ft_split.c \
			 ./ft_itoa.c \
			 ./ft_strmapi.c \
			 ./ft_striteri.c \
			 ./ft_putchar_fd.c \
			 ./ft_putstr_fd.c \
			 ./ft_putendl_fd.c \
			 ./ft_putnbr_fd.c

SRCS_FILE_BONUS = ft_lstnew_bonus.c \
				  ft_lstadd_front_bonus.c \
				  ft_lstsize_bonus.c \
				  ft_lstlast_bonus.c \
				  ft_lstadd_back_bonus.c \
				  ft_lstdelone_bonus.c \
				  ft_lstclear_bonus.c \
				  ft_lstiter_bonus.c \
				  ft_lstmap_bonus.c

OBJECT_FILE = $(SRCS_FILE:.c=.o)

OBJECT_FILE_BONUS = $(SRCS_FILE_BONUS:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

AR = ar rc

LIB = ranlib

NAME = libft.a

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME): $(OBJECT_FILE)
		$(AR) $(NAME) $(OBJECT_FILE)
		$(LIB) $(NAME)

bonus: $(OBJECT_FILE) $(OBJECT_FILE_BONUS)
		$(AR) $(NAME) $(OBJECT_FILE) $(OBJECT_FILE_BONUS)
		$(LIB) $(NAME)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRCS_FILE) $(SRCS_FILE_BONUS)
	gcc -nostartfiles -shared -o libft.so $(OBJECT_FILE) $(OBJECT_FILE_BONUS)

clean:
	rm -f $(OBJECT_FILE) $(OBJECT_FILE_BONUS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)