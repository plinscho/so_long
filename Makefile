NAME = so_long
CFLAGS = -Wall -Werror -Wextra -g

LIBFT = include/libft/libft.a
SRCDIR = src
OBJDIR = obj
HEADERS = include/so_long.h
OBJECTS = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))
MLX = include/mlx/libmlx.a

SRC = src/main.c src/map_parser.c src/error.c src/map_parse_walls.c \
		src/map_parse_items.c src/map_path.c src/img_start.c src/map_draw.c

OLD_MAKE = /usr/bin/make3.81 #make

all:
	@$(MAKE) -sC include/libft
	@$(OLD_MAKE) -sC include/mlx
	@$(MAKE) $(NAME)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@printf "Compiling objects"
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -c $< -o $@ -Iinclude/libft -Iinclude/mlx

$(NAME): $(OBJECTS) $(HEADERS) Makefile $(LIBFT) $(MLX)
	@mkdir -p $(@D)
	@gcc $(CFLAGS) -o ${NAME} ${OBJECTS} -Iinclude/libft/include -Linclude/libft -lft \
	-Iinclude/mlx -Linclude/mlx -lmlx -framework OpenGL -framework AppKit
	@printf "\nCompiled successfully!\n"

fclean: clean
	@rm -rf $(NAME)
	@$(MAKE) -C include/libft fclean
	@$(MAKE) -C include/mlx clean
	@printf "removed so_long objects\n"

clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C include/libft clean
	@$(MAKE) -C include/mlx clean
	@printf "removed so_long! & libft objects!\n"

re: fclean all

.PHONY: all clean fclean re

