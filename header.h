/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsavard <jsavard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 16:24:13 by jsavard           #+#    #+#             */
/*   Updated: 2023/01/10 13:03:47 by jsavard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <memory.h>
#include "MLX42/include/MLX42/MLX42.h"
#include "get_next_line/get_next_line.h"
#include "Libft/libft.h"

typedef struct s_game
{
	int	map_row;
	int	map_col;
	int	map_player;
	int	map_collectible;
	int	map_exit;
	int	map_walkable;
}t_game;