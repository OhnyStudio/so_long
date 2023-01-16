/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathFinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:30:47 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/12 10:19:14 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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

void	check_direction(t_game *game)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < game->map_row)
	{
		j = 1;
		while (j < game->map_col)
		{
			if (game->maps[i][j] == '0' || game->maps[i][j] == 'P'
				|| game->maps[i][j] == 'E' || game->maps[i][j] == 'C')
			{
				if (game->maps[i - 1][j] != '1')
					count += 2;
				if (game->maps[i][j + 1] != '1')
					count += 4;
				if (game->maps[i + 1][j] != '1')
					count += 8;
				if (game->maps[i][j - 1] != '1')
					count += 16;
			}
			game->value_map[i][j] = count;
			j++;
			count = 0;
		}
		i++;
	}
}

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

int	find_path(t_game *game, int i, int j)
{
	check_direction(game);
	path_finding(game, game->player_row, game->player_col);
	if (check_if_collect_left(game) != 0)
	{
		return (1);
	}
	print_map(game);
	return (0);
}
