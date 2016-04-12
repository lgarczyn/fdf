NAME = fdf

SRC = fdf.c display.c error.c mlx.c wrapper.c get_next_line.c

OBJ = $(SRC:.c=.o)

FLG = 

LIB =	-I /libft/includes \
		-I minilibx_macos \
		-lm -L./libft/ -lft -lmlx \
		-framework OpenGL -framework AppKit

DEB = -g

OPT = -O3 -ffast-math

all: $(NAME)

$(NAME): $(OBJ) 
	cd libft && make
	gcc $(FLG) $(OPT) $(OBJ) $(LIB) $(DEB) -o $(NAME)

%.o: %.c
	gcc $(FLG) $(OPT) $(DEB) -c $< $

clean:
	rm -rf $(OBJ)
	cd libft && make clean

fclean:
	rm -rf $(OBJ)
	rm -rf $(NAME)
	cd libft && make fclean

re: fclean all

optire: fclean opti
