/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/02 01:13:16 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/03 05:34:13 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_new_player_position(t_mlx *mlx, size_t new_pos)
{
	if (mlx->map->field[new_pos] == WALL || mlx->remain_frames)
		return ;
	printf("Number of moves: %zu\n", ++mlx->map->moves);
	if (mlx->map->field[new_pos] == FISH)
	{
		printf("Rescued! Remaining to save %zu children\n", --mlx->map->fish);
		mlx->map->field[new_pos] = SPACE;
	}
	update_two_cells(mlx, mlx->map->plr, new_pos);
	mlx->map->plr = new_pos;
	if (!mlx->map->fish)
		replace_exits_in_map(mlx);
	if (mlx->map->field[new_pos] == ENEMY)
		mlx->remain_frames = 20;
	if (mlx->map->field[new_pos] == EXIT2)
		end_of_game(mlx);
}
