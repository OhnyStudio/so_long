/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:02:26 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/25 15:11:18 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	validate_middle_rows(char *line, t_game *game)
{
	int	i;

	i = 0;
	if (game->map_col == (int)ft_strlen(line) - 1)
	{
		while (i < game->map_col)
		{
			if (line[i] == 'P')
				game->map_player++;
			else if (line[i] == 'E')
				game->map_exit++;
			else if (line[i] == 'C')
				game->map_collectible++;
			else if (line[i] == '0')
				game->map_floor++;
			else if (line[i] == '1')
				game->map_wall++;
			else
				return (0);
			i++;
		}
		if (line[0] == '1' && line[game->map_col - 1] == '1')
			return (1);
	}
	return (0);
}

static int	validate_rows(char *line, int row, t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = game->map_col;
	if (row == 0 || row == (game->map_row - 1))
	{
		while (i < len)
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	else
	{
		if (validate_middle_rows(line, game) == 0)
			return (0);
	}
	return (1);
}

static int	check_can_read_map(char *map_file, t_game *game)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	temp = "";
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp)
		{
			if (i == 0)
				game->map_col = ft_strlen(temp) - 1;
			if (validate_rows(temp, i, game) == 0)
				return (0);
			i++;
		}
	}
	free (temp);
	close(fd);
	return (1);
}

static int	check_map_extension(char *map_file)
{
	int	len_name;

	len_name = ft_strlen(map_file);
	if (map_file[len_name - 4] == '.' && map_file[len_name - 3] == 'b'
		&& map_file[len_name - 2] == 'e' && map_file[len_name - 1] == 'r')
	{
		return (1);
	}
	return (0);
}

int	check_map(char *map_file, t_game *game)
{
	game->map_row = calcul_number_row(map_file);
	if (check_map_extension(map_file) != 0)
	{
		if (check_can_read_map(map_file, game) != 0)
		{
			if (game->map_collectible > 0 && game->map_floor > 0
				&& game->map_player == 1 && game->map_exit == 1)
			{
				find_exit(map_file, game);
				find_player(map_file, game);
				calcul_wall(map_file, game);
				calcul_floor(map_file, game);
				set_game_size(game);
				find_collectible(map_file, game);
				find_wall(map_file, game);
				find_floor(map_file, game);
				set_map(map_file, game);
				if (path_finding(game) != 0)
					return (1);
			}
		}
	}
	return (0);
}
