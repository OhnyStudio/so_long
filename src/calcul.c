/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johnysavard <johnysavard@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:10:17 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/20 10:04:52 by johnysavard      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	calcul_number_row(char *map_file)
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

void	calcul_count_pos(t_game *game, int *count, int i, int j)
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
}

void	calcul_wall(char *map_file, t_game *game)
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
				cpt[2]++;
			cpt[1]++;
		}
		cpt[0]++;
	}
	game->map_wall = cpt[2];
	free (temp);
	close(fd);
}

void	calcul_floor(char *map_file, t_game *game)
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
			if (temp[cpt[1]] == '0' || temp[cpt[1]] == 'C'
				|| temp[cpt[1]] == 'P' || temp[cpt[1]] == 'E')
				cpt[2]++;
			cpt[1]++;
		}
		cpt[0]++;
	}
	game->map_floor = cpt[2];
	free (temp);
	close(fd);
}
