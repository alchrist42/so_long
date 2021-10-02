/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 01:11:47 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/02 21:19:49 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*
**		@brief	filles the whole window by sprites from map
*/
void	draw_map(t_mlx *mlx)
{
	size_t	i;
	char	cell;

	i = 0;
	while (i < mlx->map->cells)
	{
		update_sprite(mlx, mlx->xpm->space, i);
		cell = mlx->map->field[i];
		if (cell == WALL)
			update_sprite(mlx, mlx->xpm->wall, i);
		if (cell == PLR)
			update_sprite(mlx, mlx->xpm->player, i);
		if (cell == FISH)
			update_sprite(mlx, mlx->xpm->sprite, i);
		if (cell == EXIT)
			update_sprite(mlx, mlx->xpm->exit, i);
		i++;
	}
}

/*
**		@brief		redraws one sprite to new by their position
*/
void	update_sprite(t_mlx *mlx, void *sprite, size_t pos)
{
	int	x;
	int	y;

	x = pos % mlx->map->cols * XPM_SIZE;
	y = pos / mlx->map->cols * XPM_SIZE;
	mlx_put_image_to_window(mlx->mlx, mlx->win, sprite, x, y);
}

/*
**		@brief	Reeplaces all exit's sprites to new,
**				available to instantly quit.	
*/
void	replace_exits_in_map(t_mlx *mlx)
{
	size_t	i;

	i = 0;
	while (i < mlx->map->cells)
	{
		if (mlx->map->field[i] == EXIT)
		{
			mlx->map->field[i] = EXIT2;
			update_sprite(mlx, mlx->xpm->exit2, i);
		}
		i++;
	}
}

/*
**		@brief	Updates sprites in two cells:
**				the last player position and the new
**		
**		@param	mlx			main structure	
**		@param	old_pos		old player position
**		@param	new_pos		new player position
*/
void	update_two_cells(t_mlx *mlx, size_t old_pos, size_t new_pos)
{
	update_sprite(mlx, mlx->xpm->space, old_pos);
	update_sprite(mlx, mlx->xpm->space, new_pos);
	if (mlx->map->field[old_pos] == EXIT)
		update_sprite(mlx, mlx->xpm->exit, old_pos);
	if (mlx->map->field[new_pos] == EXIT)
		update_sprite(mlx, mlx->xpm->exit, new_pos);
	update_sprite(mlx, mlx->xpm->player, new_pos);
}
