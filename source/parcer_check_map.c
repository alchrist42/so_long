/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_check_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:55:00 by alchrist          #+#    #+#             */
/*   Updated: 2021/09/19 19:57:08 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**		@brief		checks map is surrounded by 'walls'	
*/
void	check_map_walls(t_map *map)
{
	size_t	i;

	i = 0;
	while (i < map->cells) // check left right
	{
		if (map->field[i] != '1' || map->field[i + map->cols - 1] != '1')
			ft_raise_error("Hole in left or right walls");
		i += map->cols;
	}
	i = 0;
	while (++i < map->cols)
		if (map->field[i] != '1' || map->field[map->cells - i] != '1')
			ft_raise_error("Hole in up or down walls");
}

/*
**		@brief		check player, exit and walls in the map
*/
void	check_map_content(t_map *map)
{
	size_t	i;

	i = 0;
	while (++i < map->cells)
	{
		if (!ft_strchr("01PEC", map->field[i]))
			ft_raise_error("Incorrect symbol in the map");
		if (map->field[i] == 'P' && map->plr)
			ft_raise_error("Double player in map");
		if (map->field[i] == 'P')
			map->plr = i;
		if (map->field[i] == 'E')
			map->exit++;
		if (map->field[i] == 'C')
			map->fish++;
	}
	if (!map->plr || !map->exit || !map->fish)
		ft_raise_error("No player, exit or goals in the map");
}
