/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:00:05 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/09 17:08:14 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"
#define WIDTH 256
#define HEIGHT 256

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

int	check_map(char *map_file)
{
	int	len_name;

	len_name = ft_strlen(map_file);
	if (map_file[len_name - 1] == 'r' && map_file[len_name - 2] == 'e'
		&& map_file[len_name - 1] == 'b' && map_file[len_name - 1] == '.')
	{
		return (1);
		//Check file existe
		//Open File Get_next_line
		//Check if Rectangle
		//Check if has player
		//Check if has collectible
		//Check if has exit
		//Check if has external wall
		//Check if can finish
	}
	return (0);
}

int32_t	main(int argc, char **argv)
{
	mlx_t	*mlx;

	if (argc == 2)
	{
		if (check_map(argv[1]) != 0)
		{
			mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
			if (!mlx)
				exit(EXIT_FAILURE);
			g_img = mlx_new_image(mlx, 128, 128);
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
