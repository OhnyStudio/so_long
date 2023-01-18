/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:22:27 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/18 17:04:52 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	have_2(t_game *game, int i, int j)
{
	if (game->value_map[i][j] == 2 || game->value_map[i][j] == 6
		|| game->value_map[i][j] == 10 || game->value_map[i][j] == 18
		|| game->value_map[i][j] == 14 || game->value_map[i][j] == 26
		|| game->value_map[i][j] == 22 || game->value_map[i][j] == 30)
	{
		return (1);
	}
	return (0);
}

int	have_4(t_game *game, int i, int j)
{
	if (game->value_map[i][j] == 4 || game->value_map[i][j] == 6
		|| game->value_map[i][j] == 12 || game->value_map[i][j] == 20
		|| game->value_map[i][j] == 14 || game->value_map[i][j] == 28
		|| game->value_map[i][j] == 22 || game->value_map[i][j] == 30)
	{
		return (1);
	}
	return (0);
}

int	have_8(t_game *game, int i, int j)
{
	if (game->value_map[i][j] == 8 || game->value_map[i][j] == 10
		|| game->value_map[i][j] == 12 || game->value_map[i][j] == 24
		|| game->value_map[i][j] == 14 || game->value_map[i][j] == 26
		|| game->value_map[i][j] == 28 || game->value_map[i][j] == 30)
	{
		return (1);
	}
	return (0);
}

int	have_16(t_game *game, int i, int j)
{
	if (game->value_map[i][j] == 16 || game->value_map[i][j] == 18
		|| game->value_map[i][j] == 20 || game->value_map[i][j] == 24
		|| game->value_map[i][j] == 14 || game->value_map[i][j] == 26
		|| game->value_map[i][j] == 22 || game->value_map[i][j] == 30)
	{
		return (1);
	}
	return (0);
}