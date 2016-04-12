
NAME = libft.a

FLAGS = -Wextra -Wall -Werror

OPT = -O3 -ffast-math

LFLAGS = -g

CC = gcc

AR = ar rc

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memchr.c \
	  ft_memcmp.c ft_strlen.c ft_strcpy.c ft_strdup.c ft_strcat.c \
	  ft_strncpy.c ft_strncat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_isdigit.c ft_atoi.c \
	  ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_tolower.c ft_memmove.c ft_strlcat.c ft_memalloc.c ft_memdel.c \
	  ft_strnew.c ft_strdel.c ft_strclr.c ft_striter.c ft_striteri.c \
	  ft_strmap.c ft_strmapi.c ft_strequ.c ft_strnequ.c ft_strsub.c \
	  ft_strjoin.c ft_strtrim.c ft_strsplit.c ft_itoa.c ft_putchar.c \
	  ft_putstr.c ft_putendl.c ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c \
	  ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c \
	  ft_lstadd.c ft_lstiter.c ft_lstmap.c ft_isspace.c ft_isempty.c \
	  ft_putnstr.c ft_putnstr_fd.c ft_intlen.c ft_putspace.c ft_realloc.c \
	  ft_tablen.c

RM = rm -f

NOM = $(basename $(SRC))
OBJ = $(addsuffix .o, $(NOM))

all: $(NAME)

%.o: src/%.c
	@$(CC) -g -o $@ -c $< $(FLAGS) $(OPT)

$(NAME) : $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean :
	rm -f $(OBJ)

fclean : clean
	rm -f $(NAME)

re : fclean all
