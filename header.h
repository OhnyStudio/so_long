/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:24:13 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/17 19:58:59 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "get_next_line/get_next_line.h"
#include "Libft/libft.h"

typedef struct s_game
{
	int		map_row;
	int		map_col;
	int		map_player;
	int		map_collectible;
	int		map_wall;
	int		map_exit;
	int		map_floor;
	int		player_col;
	int 	player_row;
	int		exit_col;
	int		exit_row;
	int		*collectible_col;
	int		*collectible_row;
	int		*wall_col;
	int		*wall_row;
	int		**value_map;
	char	**maps;
}	t_game;

int		have_2(t_game *game, int i, int j);
int		have_4(t_game *game, int i, int j);
int		have_8(t_game *game, int i, int j);
int		have_16(t_game *game, int i, int j);
int		find_path(t_game *game, int i, int j);
int		check_map(char *map_file, t_game *game);
int		check_path(char *map_file, t_game *game);
void	calcul_wall(char *map_file, t_game *game);
void	find_exit(char *map_file, t_game *game);
void	find_wall(char *map_file, t_game *game);
void	find_player(char *map_file, t_game *game);
void	find_collectible(char *map_file, t_game *game);
void	set_map(char *map_file, t_game *game);
void	set_game_size(t_game *game);
void	check_direction(t_game *game);
int		set_images(t_game *game);
void	test_wall(t_game *game);
