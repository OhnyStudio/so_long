/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 18:02:26 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/17 20:57:35 by johnysavard      ###   ########.fr       */
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
				return (0);
			i++;
		}
	}
	free (temp);
	close(fd);
	return (1);
}

int	check_map_extension(char *map_file)
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

void test_wall(t_game *game)
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

int	check_map(char *map_file, t_game *game)
{
	game->map_row = map_number_row(map_file);
	if (check_map_extension(map_file) != 0)
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
				calcul_wall(map_file, game);
				find_wall(map_file, game);
				set_map(map_file, game);//Bug allocation de memoire
				ft_putstr_fd("Third: ", 1);
				test_wall(game);
				if (find_path(game, 1, 1) != 0)
					return (1);
			}
		}
	}
	return (0);
}
