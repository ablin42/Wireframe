SRC_PATH = src
SRC_NAME = main.c read.c get_next_line.c
OBJ_PATH = obj
OBJ_NAME = $(SRC_NAME:.c=.o)
CPPFLAGS = -Iinclude
LDFLAGS = -L Libft -L minilibx_macos
LDLIBS = -lft -lmlx
FRAMEWORKS = -framework OpenGL -framework AppKit
NAME = fdf
CC = gcc
CFLAGS = -Werror -Wall -Wextra -fsanitize=address
SRC = $(addprefix $(SRC_PATH)/,$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) $(LDLIBS) $(FRAMEWORKS) $(OBJ) -o $(NAME)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(cFLAGS) $(CPPFLAGS) -o $@ -c $<

clean:
	rm -fv $(OBJ)
	@rmdir $(OBJ_PATH) 2> /dev/null || true

fclean: clean
	rm -fv $(NAME)

re: fclean all

norme:
	norminette $(SRC)
	norminette include/*.h

.PHONY: all, clean, fclean, re
