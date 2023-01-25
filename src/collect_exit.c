/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_exit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:24:15 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/20 10:06:07 by johnysavard      ###   ########.fr       */
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
			ft_putstr_fd("Count: ", 1);
			ft_putnbr_fd(count, 1);
			ft_putstr_fd("\n", 1);
			break ;
		}
		i++;
	}
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
		ft_putstr_fd("Win !\n", 1);
	}
}