/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:34:31 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/02 21:33:26 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_mlx	mlx;
	t_map	map;
	t_xpm	xpm;

	init_structures(&mlx, &map);
	parcer(&map, argc, argv);
	init_mlx(&mlx);
	load_textures(&mlx, &xpm);
	run_game(&mlx);
}
