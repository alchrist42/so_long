/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:13:33 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/03 05:39:05 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long_bonus.h"

// uint64_t	get_time(void)
// {
// 	struct timeval	tm;

// 	gettimeofday(&tm, NULL);
// 	return (tm.tv_sec * 1000 + tm.tv_usec / 1000);
// }

int	sprite_switcher(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	if (!(++mlx->time_cntr % 10))
	{
		while (++i < mlx->map->cells)
		{
			if (mlx->map->field[i] == ENEMY && mlx->map->plr != i)
				update_sprite(mlx, mlx->xpm->cars[mlx->time_cntr / 10 % 3 + 1], i);
			if (mlx->map->field[i] == EXIT2)
			{
				update_sprite(mlx, mlx->xpm->space, i);
				update_sprite(mlx, mlx->xpm->exit[mlx->time_cntr / 10 % 2 + 1], i);
			}
			if (mlx->remain_frames && mlx->map->plr == i)
			{
				update_sprite(mlx, mlx->xpm->space, i);
				update_sprite(mlx, mlx->xpm->cars[mlx->time_cntr / 10 % 3 + 4], i);
				mlx->remain_frames--;
			}
		}
	}
	if (mlx->remain_frames == 1)
		end_of_game(mlx);
	mlx_do_sync(mlx->mlx);
	// usleep(1000);
	return (0);
}