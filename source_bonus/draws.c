/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draws.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 01:11:47 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/03 16:52:21 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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
			update_sprite(mlx, mlx->xpm->exit[0], i);
		if (cell == ENEMY)
			update_sprite(mlx, mlx->xpm->cars[0], i);
		i++;
	}
	draw_scores(mlx);
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
			mlx->map->field[i] = EXIT2;
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
		update_sprite(mlx, mlx->xpm->exit[0], old_pos);
	if (mlx->map->field[new_pos] == EXIT)
		update_sprite(mlx, mlx->xpm->exit[0], new_pos);
	update_sprite(mlx, mlx->xpm->player, new_pos);
	draw_scores(mlx);
}

void	draw_scores(t_mlx *mlx)
{
	char	*cntr;
	char	*msg;

	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->xpm->score_cell,
		XPM_SIZE / 3, XPM_SIZE / 16);
	cntr = ft_itoa(mlx->map->moves);
	msg = ft_strjoin("MOVES:  ", cntr);
	mlx_string_put(mlx->mlx, mlx->win, XPM_SIZE / 2, XPM_SIZE / 4, SCLR, msg);
	free(cntr);
	free(msg);
	cntr = ft_itoa(mlx->map->fish);
	msg = ft_strjoin("CHILDS: ", cntr);
	mlx_string_put(mlx->mlx, mlx->win, XPM_SIZE / 2, XPM_SIZE / 2, SCLR, msg);
	free(cntr);
	free(msg);
}
