/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:31:19 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/19 17:13:54 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	can_move_up(t_game *game)
{
	if (game->maps[game->player_row - 1][game->player_col] != '1'
		&& mlx_get_time() > game->next_move)
	{
		game->player_row -= 1;
		game->player_move++;
		collect_item(game);
		can_exit(game);
		print_player_pos(game);
		return (1);
	}
	return (0);
}

int	can_move_down(t_game *game)
{
	if (game->maps[game->player_row + 1][game->player_col] != '1'
		&& mlx_get_time() > game->next_move)
	{
		game->player_row += 1;
		game->player_move++;
		collect_item(game);
		can_exit(game);
		print_player_pos(game);
		return (1);
	}
	return (0);
}

int	can_move_left(t_game *game)
{
	if (game->maps[game->player_row][game->player_col - 1] != '1'
		&& mlx_get_time() > game->next_move)
	{
		game->player_col -= 1;
		game->player_move++;
		collect_item(game);
		can_exit(game);
		print_player_pos(game);
		return (1);
	}
	return (0);
}

int	can_move_right(t_game *game)
{
	if (game->maps[game->player_row][game->player_col + 1] != '1'
		&& mlx_get_time() > game->next_move)
	{
		game->player_col += 1;
		game->player_move++;
		collect_item(game);
		can_exit(game);
		print_player_pos(game);
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
		game->player->instances[0].y -= 64;
		game->next_move = mlx_get_time() + 1;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_S) && can_move_down(game))
	{
		game->player->instances[0].y += 64;
		game->next_move = mlx_get_time() + 1;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_A) && can_move_left(game))
	{
		game->player->instances[0].x -= 64;
		game->next_move = mlx_get_time() + 1;
	}
	if (mlx_is_key_down(game->mlx, MLX_KEY_D) && can_move_right(game))
	{	
		game->player->instances[0].x += 64;
		game->next_move = mlx_get_time() + 1;
	}
}
