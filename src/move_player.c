/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:31:19 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/25 16:41:14 by jsavard          ###   ########.fr       */
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
	{
		game->player_row -= 1;
		game->player_move++;
		collect_item(game);
		print_player_move(game);
		can_exit(game);
		return (1);
	}
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
		game->player_row += 1;
		game->player_move++;
		collect_item(game);
		print_player_move(game);
		can_exit(game);
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
		game->player_col -= 1;
		game->player_move++;
		collect_item(game);
		print_player_move(game);
		can_exit(game);
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
		game->player_col += 1;
		game->player_move++;
		collect_item(game);
		print_player_move(game);
		can_exit(game);
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
