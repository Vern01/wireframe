NAME = libft.a

CFLAGS = -Wall -Werror -Wextra -c

OBJ = ft_putnbr.o ft_putstr.o ft_strsplit.o

$(NAME): all

all: $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	bin/rm 0f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

ft_putnbr.o: ft_putnbr.c
	gcc $(CFLAGS) ft_putnbr.c

ft_putstr.o: ft_putstr.c
	gcc $(CFLAGS) ft_putstr.c

ft_strsplit.o: ft_strsplit.c
	gcc $(CFLAGS) ft_strsplit.c