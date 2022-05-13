NAME = fdf

SRC =   main.c \
		read_map.c \
		get_next_line.c \
		draw_line.c

INCL = fdf.h get_next_line.h 

GCC_FLAGS = -Wall -Werror -Wextra -Imlx

MLX_LIB = minilibx_macos/libmlx.a
MLX_DIR = minilibx_macos/

FT_LIB = libft/libft.a
FT_DIR = libft/

FRAMEWORKS = -framework OpenGL -framework AppKit

OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(FT_LIB) $(NAME)

$(NAME): $(OBJ)
	@gcc $(OBJ) $(MLX_LIB) $(FT_LIB) $(FRAMEWORKS) -o $(NAME)
	@echo compiled $(NAME)

%.o: %.c ${INCL}
	@gcc $(GCC_FLAGS) -c $<
	@echo compiled $<

$(FT_LIB):
	@$(MAKE) -sC $(FT_DIR)

$(MLX_LIB):
	@$(MAKE) -sC $(MLX_DIR) make all

clean:
	rm -rf $(OBJ)
	@$(MAKE) -sC $(FT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	@$(MAKE) -sC $(FT_DIR) fclean

re: fclean all