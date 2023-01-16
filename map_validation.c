/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:02:26 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/12 11:03:50 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

static int	map_number_row(char *map_file)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	temp = "first";
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp)
			i++;
	}
	free (temp);
	close(fd);
	return (i);
}

static int	validate_middle_rows(char *line, int row, t_game *game)
{
	int	i;

	i = 0;
	if (game->map_col == ft_strlen(line))
	{
		while (i < ft_strlen(line) - 1)
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
		if (line[0] == '1' && line[game->map_col - 2] == '1')
			return (1);
	}
	return (0);
}

static int	validate_rows(char *line, int row, t_game *game)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(line);
	if (row == 1)
		len--;
	if (row == 1 || row == game->map_row)
	{
		while (i <  len)
		{
			if (line[i] != '1')
				return (0);
			i++;
		}
	}
	else
	{
		if (validate_middle_rows(line, row, game) == 0)
			return (0);
	}
	return (1);
}

static int	read_map(char *map_file, t_game *game)
{
	int		i;
	int		fd;
	char	*temp;

	i = 1;
	fd = open(map_file, O_RDONLY);
	temp = "first";
	while (temp)
	{
		temp = get_next_line(fd);
		if (temp)
		{
			if (i == 1)
				game->map_col = ft_strlen(temp);
			if (validate_rows(temp, i, game) == 0)
			{
				ft_putstr_fd("Validate Map Failed!", 1);
				return (0);
			}
			i++;
		}
	}
	free (temp);
	close(fd);
	return (1);
}

int	check_map(char *map_file, t_game *game)
{
	int	len_name;

	game->map_row = map_number_row(map_file);
	len_name = ft_strlen(map_file);
	if (map_file[len_name - 4] == '.' && map_file[len_name - 3] == 'b'
		&& map_file[len_name - 2] == 'e' && map_file[len_name - 1] == 'r')
	{
		if (read_map(map_file, game) != 0)
		{
			if (game->map_collectible > 0 && game->map_floor > 0
				&& game->map_player == 1 && game->map_exit == 1)
			{
				find_exit(map_file, game);
				find_player(map_file, game);
				set_game_size(game);
				find_collectible(map_file, game);
				set_map(map_file, game);
				if (find_path(game, 1, 1) != 0)
				{
					return (1);
				}	
			}
		}
	}
	return (0);
}
