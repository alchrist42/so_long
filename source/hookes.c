/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hookes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 01:13:16 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/02 21:29:09 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_mlx *mlx)
{
	size_t	new_pos;

	if (keycode == KEY_ESC)
		close_win(mlx);
	new_pos = mlx->map->plr;
	if (keycode == KEY_W)
		new_pos -= mlx->map->cols;
	else if (keycode == KEY_S)
		new_pos += mlx->map->cols;
	else if (keycode == KEY_A)
		new_pos -= 1;
	else if (keycode == KEY_D)
		new_pos += 1;
	else
		return (0);
	check_new_player_position(mlx, new_pos);
	return (0);
}

int	close_win(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->mlx, mlx->win);
	exit (0);
}
