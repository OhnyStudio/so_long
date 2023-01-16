/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:24:13 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/16 10:25:26 by johnysavard      ###   ########.fr       */
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
	int		map_exit;
	int		map_floor;
	int		map_wall;
	int		player_col;
	int 	player_row;
	int		exit_col;
	int		exit_row;
	int		*collectible_col;
	int		*collectible_row;
	char	**maps;
	int		**value_map;
}t_game;

int		find_path(t_game *game, int i, int j);
int		check_map(char *map_file, t_game *game);
int		check_path(char *map_file, t_game *game);
void	find_exit(char *map_file, t_game *game);
void	find_player(char *map_file, t_game *game);
void	find_collectible(char *map_file, t_game *game);
void	set_map(char *map_file, t_game *game);
void	set_game_size(t_game *game);
