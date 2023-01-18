/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:11:48 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/18 13:12:49 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
	game->collectible_col[cpt[2]] = '\0';
	game->collectible_row[cpt[2]] = '\0';
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
			if (temp[cpt[1]] == '1')
			{
				game->wall_col[cpt[2]] = cpt[1];
				game->wall_row[cpt[2]] = cpt[0];
				cpt[2]++;
			}
			cpt[1]++;
		}
		cpt[0]++;
	}
	game->wall_col[cpt[2]] = 0;
	game->wall_row[cpt[2]] = 0;
	free (temp);
	close(fd);
}