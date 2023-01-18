/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:10:17 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/18 17:15:46 by jsavard          ###   ########.fr       */
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