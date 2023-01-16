/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 20:52:47 by johnysavard       #+#    #+#             */
/*   Updated: 2023/01/11 13:06:24 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	set_map(char *map_file, t_game *game)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	while (i <= game->map_row)
	{
		temp = get_next_line(fd);
		game->maps[i] = temp;
		i++;
	}
	free (temp);
	close(fd);
}

void	find_collectible(char *map_file, t_game *game)
{
	int		cpt[3];
	int		fd;
	char	*temp;

	cpt[0] = 0;
	cpt[2] = 0;
	fd = open(map_file, O_RDONLY);
	while (cpt[0] < game->map_row)
	{
		temp = get_next_line(fd);
		cpt[1] = 0;
		while (cpt[1] < game->map_col)
		{
			if (temp[cpt[1]] == 'C')
			{
				game->collectible_col[cpt[2]] = cpt[1];
				game->collectible_row[cpt[2]] = cpt[0];
				cpt[2]++;
			}
			cpt[1]++;
		}
		cpt[0]++;
	}
	free (temp);
	close(fd);
}

void	find_player(char *map_file, t_game *game)
{
	int		i;
	int		j;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	while (i < game->map_row)
	{
		temp = get_next_line(fd);
		j = 0;
		while (temp[j])
		{
			if (temp[j] == 'P')
			{
				game->player_col = j;
				game->player_row = i;
			}
			j++;
		}
		i++;
	}
	free (temp);
	close(fd);
}

void	find_exit(char *map_file, t_game *game)
{
	int		i;
	int		j;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	temp = "first";
	while (i < game->map_row)
	{
		temp = get_next_line(fd);
		j = 0;
		while (temp[j])
		{
			if (temp[j] == 'E')
			{
				game->exit_col = j;
				game->exit_row = i;
			}
			j++;
		}
		i++;
	}
	free (temp);
	close(fd);
}

void	find_wall(char *map_file, t_game *game)
{
	int		cpt[3];
	int		fd;
	char	*temp;

	cpt[0] = 0;
	cpt[2] = 0;
	fd = open(map_file, O_RDONLY);
	while (cpt[0] < game->map_row)
	{
		temp = get_next_line(fd);
		cpt[1] = 0;
		while (cpt[1] < game->map_col)
		{
			if (temp[cpt[1]] == 'C')
			{
				game->wall_col[cpt[2]] = cpt[1];
				game->wall_row[cpt[2]] = cpt[0];
				cpt[2]++;
			}
			cpt[1]++;
		}
		cpt[0]++;
	}
	free (temp);
	close(fd);
}

void	set_game_size(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	game->collectible_col = ft_calloc(sizeof(int), game->map_col);
	game->collectible_row = ft_calloc(sizeof(int), game->map_row);
	game->maps = ft_calloc(sizeof(char *), game->map_row + 1);
	while (i < game->map_row)
	{
		game->maps[i] = ft_calloc(sizeof(char), game->map_col);
		i++;
	}
	game->value_map = ft_calloc(sizeof(int *), game->map_row + 1);
	i = 0;
	while (i < game->map_row)
	{
		game->value_map[i] = ft_calloc(sizeof(int), game->map_col);
		i++;
	}
}