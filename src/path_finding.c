/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:30:47 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/19 14:52:20 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	path_finding(t_game *game, int i, int j)
{
	if (have_2(game, i, j) != 0 && i > 0)
	{
		game->value_map[i][j] -= 2;
		path_finding(game, i - 1, j);
	}
	if (have_4(game, i, j) != 0 && j < game->map_col - 1)
	{
		game->value_map[i][j] -= 4;
		path_finding(game, i, j + 1);
	}
	if (have_8(game, i, j) != 0 && i < game->map_row - 1)
	{
		game->value_map[i][j] -= 8;
		path_finding(game, i + 1, j);
	}
	if (have_16(game, i, j) != 0 && j > 0)
	{
		game->value_map[i][j] -= 16;
		path_finding(game, i, j - 1);
	}
}

int	check_if_collect_left(t_game *game)
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

int	find_path(t_game *game)
{
	set_direction(game);
	path_finding(game, game->player_row, game->player_col);
	if (check_if_collect_left(game) != 0)
	{
		print_map(game);
		return (1);
	}
	print_map(game);
	return (0);
}
