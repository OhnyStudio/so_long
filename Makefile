NAME		=	so_long
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
MLX42		=	MLX42/Makefile.gen
LFT			=	libft/libft.a
INC			=	-I ./inc -I ./libft -I ./MLX42
LIB			=	-L ./libft -lft -L ./MLX42 -lMLX42 -lXext -lX11 -lm -lbsd
OBJ			=	$(patsubst src%, obj%, $(SRC:.c=.o))
SRC			=	src/so_long.c \
				src/calcul.c \
				src/check_direction.c \
				src/collect_exit.c \
				src/find.c \
				src/get_next_line.c \
				src/map_validation.c \
				src/move_player.c \
				src/path_finding.c \
				src/print_info.c \
				src/render_image.c \
				src/set_data.c \

all:		$(MLX42) $(LFT) obj $(NAME)

$(NAME):	$(OBJ)
			$(CC) $(FLAGS) -fsanitize=address -o $@ $^ $(LIB)

$(MLX42):
			@echo " [ .. ] | Compiling minilibx.."
			@make -s -C MLX42
		
			@echo " [ OK ] | Minilibx ready!"

$(LFT):		
			@echo " [ .. ] | Compiling libft.."
			@make -s -C libft
			@echo " [ OK ] | Libft ready!"

obj:
			@mkdir -p obj

obj/%.o:	src/%.c
			$(CC) $(FLAGS) $(INC) -o $@ -c $<

clean:
			@make -s $@ -C libft
			@rm -rf $(OBJ) obj
			@echo "object files removed."

fclean:		clean
			@make -s $@ -C libft
			@rm -rf $(NAME)
			@echo "binary file removed."

re:			fclean all