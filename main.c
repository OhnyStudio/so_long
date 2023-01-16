/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:00:05 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/16 13:01:26 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_img->instances[0].y -= 8;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_img->instances[0].y += 8;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_img->instances[0].x -= 8;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x += 8;
}

void	init_game(t_game *game)
{
	game->map_col = 0;
	game->map_row = 0;
	game->map_collectible = 0;
	game->map_exit = 0;
	game->map_floor = 0;
	game->map_player = 0;
	game->map_wall = 0;
}

int32_t	main(int argc, char **argv)
{
	t_game			game;
	mlx_t			*mlx;
	mlx_image_t		*door;
	mlx_image_t		*collect[100];
	mlx_image_t		*wall[1000];
	mlx_texture_t	*perso;
	mlx_texture_t	*db;
	mlx_texture_t	*shenron;
	int				i;

	perso = mlx_load_png("goku.png");
	db = mlx_load_png("Dragon_ball.png");
	shenron = mlx_load_png("Shenron.png");
	init_game(&game);
	if (argc == 2)
	{
		if (check_map(argv[1], &game) != 0)
		{
			mlx = mlx_init((64 * game.map_col), (64 * (game.map_row + 1)), "MLX42", true);
			if (!mlx)
				exit(EXIT_FAILURE);
			g_img = mlx_new_image(mlx, 64, 64);
			door = mlx_new_image(mlx, 64, 64);
			memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
			memset(door->pixels, 150, door->width * door->height * sizeof(int));
			i = 0;
			while (i < game.map_collectible)
			{
				collect[i] = mlx_new_image(mlx, 64, 64);
				memset(collect[i]->pixels, 200, collect[i]->width * collect[i]->height * sizeof(int));
				collect[i] = mlx_texture_to_image(mlx, db);
				mlx_image_to_window(mlx, collect[i], (game.collectible_col[i]) * 64, (game.collectible_row[i] + 1) * 64);
				i++;
			}
			while (i < game.map_collectible)
			{
				collect[i] = mlx_new_image(mlx, 64, 64);
				memset(collect[i]->pixels, 200, collect[i]->width * collect[i]->height * sizeof(int));
				collect[i] = mlx_texture_to_image(mlx, db);
				mlx_image_to_window(mlx, collect[i], (game.collectible_col[i]) * 64, (game.collectible_row[i] + 1) * 64);
				i++;
			}
			g_img = mlx_texture_to_image(mlx, perso);
			door = mlx_texture_to_image(mlx, shenron);
			mlx_image_to_window(mlx, g_img, (game.player_col) * 64, (game.player_row + 1) * 64);
			mlx_image_to_window(mlx, door, (game.exit_col) * 64, (game.exit_row + 1) * 64);
			mlx_loop_hook(mlx, &hook, mlx);
			mlx_loop(mlx);
			mlx_terminate(mlx);
			return (EXIT_SUCCESS);
		}
		else
		{
			ft_putstr_fd("Error\nMap invalide ou introuvable!", 1);
		}
	}
	else
	{
		ft_putstr_fd("Error\nMauvais parametres!", 1);
	}
}
