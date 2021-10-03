/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_resurses.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 01:11:47 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/03 16:49:54 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		ft_raise_error("Cannot initialize mlx");
	mlx->width = mlx->map->cols * XPM_SIZE;
	mlx->heigth = mlx->map->rows * XPM_SIZE;
	mlx->win = mlx_new_window(mlx->mlx, mlx->width, mlx->heigth, "so_long");
	if (!mlx->win)
		ft_raise_error("Cannot create game windows");
}

void	load_textures(t_mlx *mlx, t_xpm *xpm)
{
	char	*car_path;
	char	*end_path;

	mlx->xpm = xpm;
	load_one_texture(mlx->mlx, &xpm->player, PLAYER_XPM);
	load_one_texture(mlx->mlx, &xpm->wall, WALL_XPM);
	load_one_texture(mlx->mlx, &xpm->space, SPACE_XPM);
	load_one_texture(mlx->mlx, &xpm->sprite, SPRITE_XPM);
	load_one_texture(mlx->mlx, xpm->exit, EXIT_XPM);
	load_one_texture(mlx->mlx, xpm->exit + 1, EXIT2_XPM);
	load_one_texture(mlx->mlx, xpm->exit + 2, EXIT3_XPM);
	xpm->black_square = mlx_new_image(mlx->mlx, XPM_SIZE, XPM_SIZE);
	xpm->score_cell = mlx_new_image(mlx->mlx, XPM_SIZE * 1.5, XPM_SIZE / 2);
	end_path = ft_strdup("0.xpm");
	while (++end_path[0] < '9')
	{
		car_path = ft_strjoin(ENEMY_XPM, end_path);
		load_one_texture(mlx->mlx, xpm->cars + end_path[0] - '1', car_path);
		free(car_path);
	}
	free(end_path);
}

void	load_one_texture(void *mlx_inst, void **texture, char *path)
{
	int	x[2];

	*texture = mlx_xpm_file_to_image(mlx_inst, path, x, x + 1);
	if (!*texture)
		ft_raise_error(ft_strjoin("Cannot read texture file ", path));
	if (x[0] != x[1] || x[0] != XPM_SIZE)
		ft_raise_error(ft_strjoin("Incorrect texture size: ", path));
}
