/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:55:00 by alchrist          #+#    #+#             */
/*   Updated: 2021/09/19 19:20:06 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parcer(t_map *map, int argc, char **argv)
{
	get_map_size(map, open_map_file(argc, argv), 1);
	write_map(map, open_map_file(argc, argv));
	check_map_walls(map);
	check_map_content(map);
	

	
}

/*
**		@brief		initialises map structure by zeros	
*/
void	init_map_structure(t_map *map)
{
	map->rows = 0;
	map->cols = 0;
	map->cells = 0;
	map->plr = 0;
	map->exit = 0;
	map->fish = 0;
}
