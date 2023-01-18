/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:00:05 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/18 16:34:57 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	init_game(t_game *game)
{
	game->map_col = 0;
	game->map_row = 0;
	game->map_collectible = 0;
	game->map_exit = 0;
	game->map_floor = 0;
	game->map_player = 0;
	game->map_wall = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc == 2)
	{
		if (check_map(argv[1], &game) != 0)
		{
			run_game(&game);
		}
		else
		{
			ft_putstr_fd("Error\nMap invalide ou introuvable!", 1);
		}
	}
	else
	{
		ft_putstr_fd("Error\nMauvais parametres!", 1);
	}
}
