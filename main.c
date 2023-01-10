/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:00:05 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/10 13:21:29 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

mlx_image_t	*g_img;

void	hook(void *param)
{
	mlx_t	*mlx;

	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		g_img->instances[0].y -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_S))
		g_img->instances[0].y += 5;
	if (mlx_is_key_down(mlx, MLX_KEY_A))
		g_img->instances[0].x -= 5;
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		g_img->instances[0].x += 5;
}

int	map_row(char *map_file)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	do
	{
		temp = get_next_line(fd);
		if (temp)
		{
			i++;
		}
	}
	while (temp);
	free (temp);
	close(fd);
	return (i);
}

int	validate_map(char *line, int row, t_game *game)
{
	int	i;

	i = 0;
	if (row == 1)
	{
		while (i < ft_strlen(line) - 1)
		{
			if (line[i] != '1')
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	else if (row == game->map_row)
	{
		while (i < ft_strlen(line))
		{
			if (line[i] != '1')
			{
				return (0);
			}
			i++;
		}
		return (1);
	}
	else
	{
		if (game->map_col == ft_strlen(line))
		{
			while (i < ft_strlen(line) - 1)
			{
				if (line[i] == 'P')
				{
					game->map_player++;
					if (game->map_player > 1)
					{
						return (0);
					}
				}
				else if (line[i] == 'E')
				{
					game->map_exit++;
					if (game->map_exit > 1)
					{
						return (0);
					}
				}
				else if (line[i] == 'C')
				{
					game->map_collectible++;
				}
				else if (line[i] == '0')
				{
					game->map_walkable++;
				}
				else if (line[i] == '1')
				{
					
				}
				else
				{
					return (0);
				}
				i++;
			}
			if (line[0] == '1' && line[game->map_col - 2] == '1')
			{
				return (1);
			}
		}
	}
	return (0);
}

int	read_map(char *map_file, t_game *game)
{
	int		i;
	int		fd;
	char	*temp;

	i = 0;
	fd = open(map_file, O_RDONLY);
	game->map_row = map_row(map_file);
	do
	{
		temp = get_next_line(fd);
		if (temp)
		{
			i++;
			ft_putnbr_fd(i, 1);
			ft_putstr_fd(" - ", 1);
			ft_putstr_fd(temp, 1);
			if (i == 1)
			{
				game->map_col = ft_strlen(temp);
			}
			if (validate_map(temp, i, game) == 0)
			{
				ft_putchar_fd('X', 1);
				return (0);
			}
		}
	}
	while (temp);
	free (temp);
	close(fd);
	return (i);
}

int	check_map(char *map_file, t_game *game)
{
	int		len_name;

	len_name = ft_strlen(map_file);
	if (map_file[len_name - 1] == 'r' && map_file[len_name - 2] == 'e'
		&& map_file[len_name - 3] == 'b' && map_file[len_name - 4] == '.')
	{
		if (read_map(map_file, game) != 0)
		{
			ft_putnbr_fd(game->map_collectible, 1);
			ft_putnbr_fd(game->map_player, 1);
			if (game->map_collectible > 0 && game->map_walkable > 1
			&& game->map_player == 1 && game->map_exit == 1)
			{
				return (1);
			}
		}
		//Check if can finish
	}
	return (0);
}

int32_t	main(int argc, char **argv)
{
	t_game	game;
	mlx_t	*mlx;

	if (argc == 2)
	{
		if (check_map(argv[1], &game) != 0)
		{
			mlx = mlx_init((64 * game.map_col), (64 * (game.map_row + 1)), "MLX42", true);
			if (!mlx)
				exit(EXIT_FAILURE);
			g_img = mlx_new_image(mlx, 64, 64);
			memset(g_img->pixels, 255, g_img->width * g_img->height * sizeof(int));
			mlx_image_to_window(mlx, g_img, 0, 0);
			mlx_loop_hook(mlx, &hook, mlx);
			mlx_loop(mlx);
			mlx_terminate(mlx);
			return (EXIT_SUCCESS);
		}
		else
		{
			ft_putstr_fd("Error\nMap invalide !", 1);
		}
	}
	else
	{
		ft_putstr_fd("Error\nMauvais parametres !", 1);
	}
}
