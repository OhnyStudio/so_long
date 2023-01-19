/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 16:27:49 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/19 17:11:49 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_value_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_row)
	{
		j = 0;
		while (j < game->map_col)
		{
			if (game->value_map[i][j] < 10)
				ft_putstr_fd(" ", 1);
			ft_putnbr_fd(game->value_map[i][j], 1);
			ft_putstr_fd(" ", 1);
			j++;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	print_map(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map_row)
	{
		j = 0;
		while (j < game->map_col)
		{
			ft_putchar_fd(game->maps[i][j], 1);
			j++;
		}
		i++;
	}
	ft_putstr_fd("\n", 1);
	print_value_map(game);
}

void	print_wall(t_game *game)
{
	int	i;

	i = 0;
	ft_putstr_fd("Col: ", 1);
	ft_putnbr_fd(game->map_col, 1);
	ft_putstr_fd("\nRow: ", 1);
	ft_putnbr_fd(game->map_row, 1);
	ft_putstr_fd("\nWall: ", 1);
	ft_putnbr_fd(game->map_wall, 1);
	ft_putstr_fd("\n", 1);
	while (i < game->map_wall)
	{
		ft_putnbr_fd(i, 1);
		ft_putstr_fd(" - Pos Wall: ", 1);
		ft_putnbr_fd(game->wall_col[i], 1);
		ft_putstr_fd(",", 1);
		ft_putnbr_fd(game->wall_row[i] + 1, 1);
		ft_putstr_fd("\n", 1);
		i++;
	}
}

void	print_player_pos(t_game *game)
{
	ft_putstr_fd("Player Pos: ", 1);
	ft_putnbr_fd(game->player_row, 1);
	ft_putstr_fd(",", 1);
	ft_putnbr_fd(game->player_col, 1);
	ft_putstr_fd("\nPlayer movement: ", 1);
	ft_putnbr_fd(game->player_move, 1);
	ft_putstr_fd("\nCollectible left: ", 1);
	ft_putnbr_fd(game->map_collectible, 1);
	ft_putstr_fd("\n", 1);
}