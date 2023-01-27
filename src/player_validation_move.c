/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_validation_move.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 09:43:47 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/27 09:43:48 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	delete_db_image(t_game	*game)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (game->collect[i])
	{
		if (game->collect_col[i] != game->player_col
			|| game->collect_row[i] != game->player_row)
			count++;
		else
		{
			mlx_delete_image(game->mlx, game->collect[count]);
			break ;
		}
		i++;
	}
}

static int	check_if_collect_left(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_row)
	{
		j = 0;
		while (j < game->map_col)
		{
			if (game->value_map[i][j] > 0)
			{
				if (game->maps[i][j] == 'C' || game->maps[i][j] == 'C')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	player_can_finish(t_game *game)
{
	set_direction(game);
	check_all_direction(game, game->player_row, game->player_col);
	if (check_if_collect_left(game) != 0)
		return (1);
	return (0);
}

void	collect_item(t_game *game)
{
	if (game->maps[game->player_row][game->player_col] == 'C')
	{
		game->map_collectible--;
		game->maps[game->player_row][game->player_col] = '0';
		delete_db_image(game);
	}
}

void	can_exit(t_game *game)
{
	if (game->map_collectible == 0
		&& game->maps[game->player_row][game->player_col] == 'E')
	{
		mlx_put_string(game->mlx, "You Won in ", 10, game->map_row * 64 + 40);
		game->txt_move = mlx_put_string(game->mlx,
				ft_itoa(game->player_move), 120, game->map_row * 64 + 40);
		game->game_finish = 1;
		mlx_put_string(game->mlx,
			" moves! Close to restart!", 140, game->map_row * 64 + 40);
	}
}
