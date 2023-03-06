/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:32:25 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/06 10:30:48 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include <fcntl.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_game
{
	int				second_move;
	int				game_finish;
	int				map_row;
	int				map_col;
	int				map_wall;
	int				map_exit;
	int				exit_col;
	int				exit_row;
	int				map_floor;
	int				next_move;
	int				map_player;
	int				player_col;
	int				player_row;
	int				player_move;
	int				map_collectible;
	int				*wall_col;
	int				*wall_row;
	int				*floor_col;
	int				*floor_row;
	int				*collect_col;
	int				*collect_row;
	int				**value_map;
	char			**maps;
	mlx_t			*mlx;
	mlx_image_t		*txt_collect_count;
	mlx_image_t		*txt_collect;
	mlx_image_t		*txt_move_count;
	mlx_image_t		*txt_move;
	mlx_image_t		*door;
	mlx_image_t		*player;
	mlx_image_t		**wall;
	mlx_image_t		**floor;
	mlx_image_t		**collect;
	mlx_texture_t	*db;
	mlx_texture_t	*perso;
	mlx_texture_t	*shenron;
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*floor_texture;
}	t_game;

//Free Game
void	free_game(t_game *game, int isRender);
//Map Calcul
int		calcul_number_row(char *map_file);
int		calcul_count_pos(t_game *game, int i, int j);
void	calcul_move(t_game *game);
void	calcul_wall(char *map_file, t_game *game);
void	calcul_floor(char *map_file, t_game *game);
//Map find
void	find_exit(char *map_file, t_game *game);
void	find_wall(char *map_file, t_game *game);
void	find_floor(char *map_file, t_game *game);
void	find_player(char *map_file, t_game *game);
void	find_collectible(char *map_file, t_game *game);
//Map get next line
char	*get_next_line(int fd);
//Map render image
int		render_game(t_game *game);
//Map render str
void	print_player_move(t_game *game);
//Map Set Data
void	set_direction(t_game *game);
void	set_game_size(t_game *game);
void	set_map(char *map_file, t_game *game);
//Map Valiadtion Direction
void	check_all_direction(t_game *game, int i, int j);
//Map Valiadtion
int		check_map(char *map_file, t_game *game);
//Player Move
void	hook(void *params);
//Player Validation Move
int		player_can_finish(t_game *game);
void	can_exit(t_game *game);
void	collect_item(t_game *game);
#endif