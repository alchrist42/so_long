/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 00:13:33 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/03 17:14:16 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	sprite_switcher(t_mlx *mlx)
{
	size_t	i;

	if (mlx->bear_on_fire)
		bad_final(mlx);
	i = 0;
	if (!(++mlx->frame % 10))
	{
		while (++i < mlx->map->cells)
		{
			if (mlx->map->field[i] == ENEMY && mlx->map->plr != i)
				update_sprite(mlx, mlx->xpm->cars[mlx->frame / 10 % 3 + 1], i);
			if (mlx->map->field[i] == EXIT2)
			{
				update_sprite(mlx, mlx->xpm->space, i);
				update_sprite(mlx, mlx->xpm->exit[mlx->frame / 10 % 2 + 1], i);
			}
		}
	}
	mlx_do_sync(mlx->mlx);
	return (0);
}

void	bad_final(t_mlx *mlx)
{
	size_t	plr;
	size_t	f;

	plr = mlx->map->plr;
	shadows_map(mlx, plr);
	f = 0;
	while (++f < EXIT_TIME / 2)
	{
		if (f % 10)
		{
			update_sprite(mlx, mlx->xpm->black_square, plr);
			update_sprite(mlx, mlx->xpm->cars[f / 10 % 4 + 4], plr);
		}
		mlx_do_sync(mlx->mlx);
	}
	end_of_game(mlx);
}

void	good_final(t_mlx *mlx, size_t plr_pos)
{
	size_t	frame;

	frame = 0;
	while (++frame <= EXIT_TIME)
	{
		if (frame % 10)
		{
			update_sprite(mlx, mlx->xpm->space, plr_pos);
			if (frame <= EXIT_TIME / 2)
				update_sprite(mlx, mlx->xpm->player, plr_pos);
			update_sprite(mlx, mlx->xpm->exit[frame / 10 % 2 + 1], plr_pos);
		}
		mlx_do_sync(mlx->mlx);
	}
	end_of_game(mlx);
}

void	shadows_map(t_mlx *mlx, size_t plr_pos)
{
	size_t	frame;

	frame = 0;
	while (++frame <= EXIT_TIME / 5)
	{
		if (frame % 10)
		{
			update_sprite(mlx, mlx->xpm->space, plr_pos);
			update_sprite(mlx, mlx->xpm->cars[frame / 10 % 4 + 4], plr_pos);
		}
		mlx_do_sync(mlx->mlx);
	}
	frame = 0;
	while (frame <= mlx->map->cells)
		update_sprite(mlx, mlx->xpm->black_square, frame++ % mlx->map->cells);
}
