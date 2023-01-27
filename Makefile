NAME 		=	so_long
CC 			=	gcc
CFLAGS 		=	-Wall -Wextra -Werror -g
MLX_PATH	=	MLX42/
MLX_LIB 	=	$(MLX_PATH)lib/lib-x86_64/libglfw3.a $(MLX_PATH)libmlx42.a
MLX_FLAGS	=	-framework Cocoa -framework OpenGL -framework IOKit
LIBFT_PATH	=	libft/
LIBFT_LIB	=	$(LIBFT_PATH)libft.a
CFILES		=	src/free_game.c \
				src/map_calcul.c \
				src/map_find.c \
				src/map_get_next_line.c \
				src/map_render_image.c \
				src/map_render_str.c \
				src/map_set_data.c \
				src/map_validation_direction.c \
				src/map_validation.c \
				src/player_move.c \
				src/player_validation_move.c \
				src/so_long.c
Y			=	"\033[33m"
R			=	"\033[31m"
G			=	"\033[32m"
B			=	"\033[34m"
X			=	"\033[0m"
UP			=	"\033[A"
CUT			=	"\033[K"
OBJECTS		=	$(CFILES:.c=.o)

all: subsystems $(NAME)

%.o : %.c
	@echo $(Y)Compiling [$<]...$(X)
	@$(CC) $(CFLAGS) -Imlx -c -o $@ $<
	@printf $(UP)$(CUT)

subsystems:
	@echo $(B)
	make -C $(MLX_PATH) all
	@echo $(B)
	make -C $(LIBFT_PATH) all

$(NAME): $(OBJECTS)
	@echo $(Y)Compiling [$(CFILES)]...$(X)
	@echo $(G)Finished [$(CFILES)]$(X)
	@echo
	@echo $(Y)Compiling [$(NAME)]...$(X)
	@$(CC) $(CFLAGS) $(MLX_FLAGS) $(OBJECTS) $(MLX_LIB) $(LIBFT_LIB) -o $(NAME)
	@echo $(G)Finished [$(NAME)]$(X)

clean:
	@make -C $(MLX_PATH) clean
	@make -C $(LIBFT_PATH) clean
	@rm -f $(OBJECTS)
	@echo $(R)Removed [$(OBJECTS)]$(X)

fclean: clean
	@make -C $(MLX_PATH) fclean
	@make -C $(LIBFT_PATH) fclean
	@rm -f $(NAME)
	@echo $(R)Removed [$(NAME)]$(X)

re: fclean all