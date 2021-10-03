/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:55:00 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/02 22:17:33 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
**		@brief		checks map is surrounded by 'walls'	
*/
void	check_map_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->cells)
	{
		if (map->field[i] != WALL || map->field[i + map->cols - 1] != WALL)
			ft_raise_error("Hole in left or right walls");
		i += map->cols;
	}
	i = 0;
	while (++i < map->cols)
		if (map->field[i] != WALL || map->field[map->cells - i] != WALL)
			ft_raise_error("Hole in up or down walls");
}

/*
**		@brief		check player, exit and fish in the map
*/
void	check_map_content(t_map *map)
{
	size_t	i;

	i = 0;
	while (++i < map->cells)
	{
		if (!ft_strchr("01PECM", map->field[i]))
			ft_raise_error("Incorrect symbol in the map");
		if (map->field[i] == PLR && map->plr)
			ft_raise_error("Double player in map");
		if (map->field[i] == PLR)
			map->plr = i;
		if (map->field[i] == EXIT)
			map->exit++;
		if (map->field[i] == FISH)
			map->fish++;
	}
	if (!map->plr || !map->exit || !map->fish)
		ft_raise_error("No player, exit or goals in the map");
}
