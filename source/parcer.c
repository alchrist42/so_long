/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:55:00 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/02 21:30:14 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**		@brief	loads and checks map file
*/
void	parcer(t_map *map, int argc, char **argv)
{
	get_map_size(map, open_map_file(argc, argv), 1);
	write_map(map, open_map_file(argc, argv));
	check_map_walls(map);
	check_map_content(map);
}

/*
**		@brief	initialises main and map structures	
*/
void	init_structures(t_mlx *mlx, t_map *map)
{
	mlx->map = map;
	mlx_get_screen_size(&mlx->res_x, &mlx->res_y);
	map->max_width = mlx->res_x / XPM_SIZE - 1;
	map->max_height = mlx->res_y / XPM_SIZE - 1;
	map->rows = 0;
	map->cols = 0;
	map->cells = 0;
	map->plr = 0;
	map->exit = 0;
	map->fish = 0;
	map->moves = 0;
}
