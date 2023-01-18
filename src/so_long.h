/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 16:32:25 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/18 17:12:16 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <memory.h>
# include "../MLX42/include/MLX42/MLX42.h"
# include "../get_next_line/get_next_line.h"
# include "../Libft/libft.h"

typedef struct s_game
{
	int				map_row;
	int				map_col;
	int				map_wall;
	int				map_exit;
	int				exit_col;
	int				exit_row;
	int				map_floor;
	int				map_player;
	int				player_col;
	int				player_row;
	int				map_collectible;
	int				*wall_col;
	int				*wall_row;
	int				*collectible_col;
	int				*collectible_row;
	int				**value_map;
	char			**maps;
	mlx_t			*mlx;
	mlx_image_t		*door;
	mlx_image_t		**wall;
	mlx_image_t		**collect;
	mlx_texture_t	*db;
	mlx_texture_t	*perso;
	mlx_texture_t	*shenron;
	mlx_texture_t	*wall_texture;
}	t_game;

int		run_game(t_game *game);
int		can_move_up(t_game *game);
int		can_move_down(t_game *game);
int		can_move_left(t_game *game);
int		can_move_right(t_game *game);
int		calcul_number_row(char *map_file);
int		have_2(t_game *game, int i, int j);
int		have_4(t_game *game, int i, int j);
int		have_8(t_game *game, int i, int j);
int		have_16(t_game *game, int i, int j);
int		find_path(t_game *game, int i, int j);
int		check_map(char *map_file, t_game *game);
int		check_path(char *map_file, t_game *game);
void	print_map(t_game *game);
void	print_wall(t_game *game);
void	set_game_size(t_game *game);
void	set_direction(t_game *game);
void	print_value_map(t_game *game);
void	set_map(char *map_file, t_game *game);
void	find_exit(char *map_file, t_game *game);
void	find_wall(char *map_file, t_game *game);
void	find_player(char *map_file, t_game *game);
void	calcul_wall(char *map_file, t_game *game);
void	calcul_wall(char *map_file, t_game *game);
void	set_player_image(mlx_t *mlx, t_game *game);
void	find_collectible(char *map_file, t_game *game);
void	calcul_count_pos(t_game *game, int *count, int i, int j);
#endif