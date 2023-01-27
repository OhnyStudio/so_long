/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 10:49:34 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/27 14:52:34 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delete_textures(t_game *game)
{
	mlx_delete_texture(game->db);
	mlx_delete_texture(game->perso);
	mlx_delete_texture(game->shenron);
	mlx_delete_texture(game->wall_texture);
	mlx_delete_texture(game->floor_texture);
}

static void	delete_images(t_game *game)
{
	int	i;

	i = 0;
	while (game->floor[i])
	{
		mlx_delete_image(game->mlx, game->floor[i]);
		i++;
	}
	free(game->floor);
	i = 0;
	while (game->collect[i])
	{
		mlx_delete_image(game->mlx, game->collect[i]);
		i++;
	}
	free(game->collect);
	i = 0;
	while (game->wall[i])
	{
		mlx_delete_image(game->mlx, game->wall[i]);
		i++;
	}
	free(game->wall);
}

static void	free_array(t_game *game)
{
	int	i;

	free(game->wall_col);
	free(game->wall_row);
	free(game->floor_col);
	free(game->floor_row);
	free(game->collect_col);
	free(game->collect_row);
	i = 0;
	while (game->value_map[i])
	{
		free (game->value_map[i]);
		i++;
	}
	free (game->value_map);
	i = 0;
	while (game->maps[i])
	{
		free (game->maps[i]);
		i++;
	}
	free (game->maps);
}

void	free_game(t_game *game)
{
	delete_textures(game);
	delete_images(game);
	free_array(game);
}
