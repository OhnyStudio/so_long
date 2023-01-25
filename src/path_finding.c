/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_finding.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:30:47 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/20 11:07:32 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	path_finding(t_game *game)
{
	set_direction(game);
	check_all_direction(game, game->player_row, game->player_col);
	if (check_if_collect_left(game) != 0)
	{
		print_map(game);
		return (1);
	}
	print_map(game);
	return (0);
}
