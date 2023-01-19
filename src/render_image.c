/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_image.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:44:05 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/19 14:53:37 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

mlx_image_t	*g_img;
t_game		*game2;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W) && can_move_up(game2))
		g_img->instances[0].y -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_S) && can_move_down(game2))
		g_img->instances[0].y += 64;
	if (mlx_is_key_down(mlx, MLX_KEY_A) && can_move_left(game2))
		g_img->instances[0].x -= 64;
	if (mlx_is_key_down(mlx, MLX_KEY_D) && can_move_right(game2))
		g_img->instances[0].x += 64;
}

int	run_game(t_game *game)
{
	int				i;

	game2 = game;
	game->perso = mlx_load_png("images/goku.png");
	game->db = mlx_load_png("images/Dragon_ball.png");
	game->shenron = mlx_load_png("images/Shenron.png");
	game->wall_texture = mlx_load_png("images/wall.png");
	game->floor_texture = mlx_load_png("images/floor.png");
	game->mlx = mlx_init((64 * (game->map_col - 1)), (64 * (game->map_row + 1)), "MLX42", true);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	g_img = mlx_new_image(game->mlx, 64, 64);
	game->door = mlx_new_image(game->mlx, 64, 64);
	memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
	memset(game->door->pixels, 150, game->door->width * game->door->height * sizeof(int));
	i = 0;
	while (i < game->map_floor)
	{
		game->floor[i] = mlx_new_image(game->mlx, 64, 64);
		memset(game->floor[i]->pixels, 200, game->floor[i]->width * game->floor[i]->height * sizeof(int));
		game->floor[i] = mlx_texture_to_image(game->mlx, game->floor_texture);
		mlx_image_to_window(game->mlx, game->floor[i], (game->floor_col[i]) * 64, (game->floor_row[i] + 1) * 64);
		i++;
	}
	i = 0;
	while (i < game->map_collectible)
	{
		game->collect[i] = mlx_new_image(game->mlx, 64, 64);
		memset(game->collect[i]->pixels, 200, game->collect[i]->width * game->collect[i]->height * sizeof(int));
		game->collect[i] = mlx_texture_to_image(game->mlx, game->db);
		mlx_image_to_window(game->mlx, game->collect[i], (game->collectible_col[i]) * 64, (game->collectible_row[i] + 1) * 64);
		i++;
	}
	i = 0;
	while (i < game->map_wall)
	{
		game->wall[i] = mlx_new_image(game->mlx, 64, 64);
		memset(game->wall[i]->pixels, 200, game->wall[i]->width * game->wall[i]->height * sizeof(int));
		game->wall[i] = mlx_texture_to_image(game->mlx, game->wall_texture);
		mlx_image_to_window(game->mlx, game->wall[i], (game->wall_col[i]) * 64, (game->wall_row[i] + 1) * 64);
		i++;
	}
	g_img = mlx_texture_to_image(game->mlx, game->perso);
	game->door = mlx_texture_to_image(game->mlx, game->shenron);
	mlx_image_to_window(game->mlx, g_img, (game->player_col) * 64, (game->player_row + 1) * 64);
	mlx_image_to_window(game->mlx, game->door, (game->exit_col) * 64, (game->exit_row + 1) * 64);
	mlx_loop_hook(game->mlx, &hook, game->mlx);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (EXIT_SUCCESS);
}