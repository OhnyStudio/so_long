/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:00:05 by jsavard           #+#    #+#             */
/*   Updated: 2023/03/14 14:37:16 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	init_game(t_game *game)
{
	game->game_finish = 0;
	game->map_col = 0;
	game->map_row = 0;
	game->map_collectible = 0;
	game->map_exit = 0;
	game->map_floor = 0;
	game->map_player = 0;
	game->map_wall = 0;
	game->player_move = 0;
	game->next_move = 0;
	game->game_state = 0;
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_game(&game);
	if (argc == 2)
	{
		if (check_map(argv[1], &game) != 0)
			render_game(&game);
		else
		{
			ft_putstr_fd("Error\nMap invalide ou introuvable!\n", 1);
			if (game.game_state > 0)
				free_game(&game, 0);
		}
	}
	else
		ft_putstr_fd("Error\nMauvais parametres!\n", 1);
	return (0);
}
