/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:24:15 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/19 17:15:02 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	collect_item(t_game *game)
{
	int	i;
	int	j;
	int	count;

	if (game->maps[game->player_row][game->player_col] == 'C')
	{
		game->map_collectible--;
		game->maps[game->player_row][game->player_col] = 0;
	}
	i = 1;
	count = 0;
	while (i < game->map_row)
	{
		j = 1;
		while (j < game->map_col)
		{
			if (game->maps[i][j] == 'C')
			{
				if (i == game->player_row && j == game->player_col)
					mlx_delete_image(game->mlx, game->collect[count]);
				count++;
			}
			j++;
		}
		i++;
	}
}

void	can_exit(t_game *game)
{
	if (game->map_collectible == 0 &&
		game->maps[game->player_row][game->player_col] == 'E')
	{
		ft_putstr_fd("Win !", 1);
	}
}