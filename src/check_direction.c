/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_direction.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:22:27 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/20 11:13:43 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	have_2(t_game *game, int i, int j)
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

static int	have_4(t_game *game, int i, int j)
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

static int	have_8(t_game *game, int i, int j)
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

static int	have_16(t_game *game, int i, int j)
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

void	check_all_direction(t_game *game, int i, int j)
{
	if (have_2(game, i, j) != 0 && i > 0)
	{
		game->value_map[i][j] -= 2;
		check_all_direction(game, i - 1, j);
	}
	if (have_4(game, i, j) != 0 && j < game->map_col - 1)
	{
		game->value_map[i][j] -= 4;
		check_all_direction(game, i, j + 1);
	}
	if (have_8(game, i, j) != 0 && i < game->map_row - 1)
	{
		game->value_map[i][j] -= 8;
		check_all_direction(game, i + 1, j);
	}
	if (have_16(game, i, j) != 0 && j > 0)
	{
		game->value_map[i][j] -= 16;
		check_all_direction(game, i, j - 1);
	}
}
