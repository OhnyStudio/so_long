/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:31:19 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/18 14:51:03 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	can_move_up(t_game *game)
{
	if (game->maps[game->player_row - 1][game->player_col] != '1')
	{
		game->player_row -= 1;
		return (1);
	}
	return (0);
}

int	can_move_down(t_game *game)
{
	if (game->maps[game->player_row + 1][game->player_col] != '1')
	{
		game->player_row += 1;
		return (1);
	}
	return (0);
}

int	can_move_left(t_game *game)
{
	if (game->maps[game->player_row][game->player_col - 1] != '1')
	{
		game->player_col -= 1;
		return (1);
	}
	return (0);
}

int	can_move_right(t_game *game)
{
	if (game->maps[game->player_row + 1][game->player_col + 1] != '1')
	{
		game->player_col += 1;
		return (1);
	}
	return (0);
}