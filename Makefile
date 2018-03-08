NAME = FdF
SRCS = wire.c
INCLUDES = ?
FLAGS = NOFLAGSYET put it in gcc -c
OBJS = $(OBJ:.c=.o)

all: $(NAME)


$(NAME):
	gcc -c $(SRCS)
	gcc $(SRCS) -o $(NAME) /Users/ablin/42/FdF/minilibx_macos/ -lmlx -framework OpenGL -framework AppKit

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
