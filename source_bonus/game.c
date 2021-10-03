/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 01:11:47 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/03 00:42:20 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	run_game(t_mlx *mlx)
{
	printf("Welcome to game!\nYou should find and save all children.\n");
	draw_map(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_hook(mlx->win, 17, 1L << 1, close_win, mlx);
	mlx_loop_hook(mlx->mlx, sprite_switcher, mlx);
	mlx_loop(mlx->mlx);
}

void	end_of_game(t_mlx *mlx)
{
	if (!mlx->map->fish)
		printf("You successfully saved all children from the Dark forest!\n");
	printf("The END\n");
	close_win(mlx);
}
