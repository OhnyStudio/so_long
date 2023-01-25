/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:44:05 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/25 14:10:35 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	set_texture(t_game *game)
{
	game->perso = mlx_load_png("images/goku.png");
	game->db = mlx_load_png("images/Dragon_ball.png");
	game->shenron = mlx_load_png("images/Shenron.png");
	game->wall_texture = mlx_load_png("images/wall.png");
	game->floor_texture = mlx_load_png("images/floor.png");
}

static void	set_player_exit(t_game *game)
{
	game->player = mlx_new_image(game->mlx, 64, 64);
	game->door = mlx_new_image(game->mlx, 64, 64);
	memset(game->player->pixels, 255,
		game->player->width * game->player->height * sizeof(int));
	memset(game->door->pixels, 150,
		game->door->width * game->door->height * sizeof(int));
	game->player = mlx_texture_to_image(game->mlx, game->perso);
	game->door = mlx_texture_to_image(game->mlx, game->shenron);
}

static void	set_floors_walls(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_floor)
	{
		game->floor[i] = mlx_new_image(game->mlx, 64, 64);
		memset(game->floor[i]->pixels, 200,
			game->floor[i]->width * game->floor[i]->height * sizeof(int));
		game->floor[i] = mlx_texture_to_image(game->mlx, game->floor_texture);
		mlx_image_to_window(game->mlx, game->floor[i],
			(game->floor_col[i]) * 64, (game->floor_row[i] + 1) * 64);
		i++;
	}
	i = 0;
	while (i < game->map_wall)
	{
		game->wall[i] = mlx_new_image(game->mlx, 64, 64);
		memset(game->wall[i]->pixels, 200,
			game->wall[i]->width * game->wall[i]->height * sizeof(int));
		game->wall[i] = mlx_texture_to_image(game->mlx, game->wall_texture);
		mlx_image_to_window(game->mlx, game->wall[i],
			(game->wall_col[i]) * 64, (game->wall_row[i] + 1) * 64);
		i++;
	}
}

static void	set_collectibles(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map_collectible)
	{
		game->collect[i] = mlx_new_image(game->mlx, 64, 64);
		memset(game->collect[i]->pixels, 200,
			game->collect[i]->width * game->collect[i]->height * sizeof(int));
		game->collect[i] = mlx_texture_to_image(game->mlx, game->db);
		mlx_image_to_window(game->mlx, game->collect[i],
			(game->collect_col[i]) * 64, (game->collect_row[i] + 1) * 64);
		i++;
	}
}

int	render_game(t_game *game)
{
	set_texture(game);
	game->mlx = mlx_init((64 * game->map_col),
			(64 * (game->map_row + 1)), "MLX42", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	set_player_exit(game);
	set_floors_walls(game);
	set_collectibles(game);
	mlx_image_to_window(game->mlx, game->player,
		(game->player_col) * 64, (game->player_row + 1) * 64);
	mlx_image_to_window(game->mlx, game->door,
		(game->exit_col) * 64, (game->exit_row + 1) * 64);
	mlx_loop_hook(game->mlx, &hook, (void *)game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}
