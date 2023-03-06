/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:31:19 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/06 16:25:32 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	can_move_up(t_game *game)
{
	if ((game->maps[game->player_row - 1][game->player_col] == '0'
		|| game->maps[game->player_row - 1][game->player_col] == 'C'
		|| game->maps[game->player_row - 1][game->player_col] == 'P'
		|| game->maps[game->player_row - 1][game->player_col] == 'E')
		&& mlx_get_time() > game->next_move && game->game_finish != 1)
		return (1);
	return (0);
}

static int	can_move_down(t_game *game)
{
	if ((game->maps[game->player_row + 1][game->player_col] == '0'
		|| game->maps[game->player_row + 1][game->player_col] == 'C'
		|| game->maps[game->player_row + 1][game->player_col] == 'E'
		|| game->maps[game->player_row + 1][game->player_col] == 'P')
		&& mlx_get_time() > game->next_move && game->game_finish != 1)
	{
		return (1);
	}
	return (0);
}

static int	can_move_left(t_game *game)
{
	if ((game->maps[game->player_row][game->player_col - 1] == '0'
		|| game->maps[game->player_row][game->player_col - 1] == 'C'
		|| game->maps[game->player_row][game->player_col - 1] == 'P'
		|| game->maps[game->player_row][game->player_col - 1] == 'E')
		&& mlx_get_time() > game->next_move && game->game_finish != 1)
	{
		return (1);
	}
	return (0);
}

static int	can_move_right(t_game *game)
{
	if ((game->maps[game->player_row][game->player_col + 1] == '0'
		|| game->maps[game->player_row][game->player_col + 1] == 'C'
		|| game->maps[game->player_row][game->player_col + 1] == 'E'
		|| game->maps[game->player_row][game->player_col + 1] == 'P')
		&& mlx_get_time() > game->next_move && game->game_finish != 1)
	{
		return (1);
	}
	return (0);
}

void	hook(void *params)
{
	t_game	*game;

	game = params;
	if (mlx_is_key_down(game->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(game->mlx);
	if (mlx_is_key_down(game->mlx, MLX_KEY_W) && can_move_up(game))
	{
		collect_item(game, 0);
		game->player->instances[0].y -= 64;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_S) && can_move_down(game))
	{
		collect_item(game, 1);
		game->player->instances[0].y += 64;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_A) && can_move_left(game))
	{
		collect_item(game, 2);
		game->player->instances[0].x -= 64;
	}
	else if (mlx_is_key_down(game->mlx, MLX_KEY_D) && can_move_right(game))
	{	
		collect_item(game, 3);
		game->player->instances[0].x += 64;
	}
}
