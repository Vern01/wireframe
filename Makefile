NAME = wireframe

SRC = main.c read_file.c get_next_line.c add_to_array.c draw_line.c set_cor.c solve_through_x.c \
solve_through_y.c swap_points.c draw.c set_line_info.c rotate_x.c rotate_y.c rotate_z.c key_hook.c

OBJ = $(SRC:.c=.o)

CFLAG = -Wall -Werror -Wextra -g3

MAKE_LIBFT = make -C libft/

INCLUDES = -I . -I libft

ATTACH = -L ./libft -lft -lm -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME):
	$(MAKE_LIBFT)
	gcc $(CFLAG) $(INCLUDES) -c $(SRC)
	gcc $(CFLAG) -o $(NAME)	$(OBJ) $(ATTACH)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
