/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:35:56 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/02 21:43:09 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <fcntl.h> 

# include <stdbool.h>
# include <stdio.h>
# include <sys/errno.h>

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

# define XPM_SIZE	64

# define SPACE	'0'
# define WALL	'1'
# define PLR	'P'
# define EXIT	'E'
# define EXIT2	'Q'
# define FISH	'C'

# define PLAYER_XPM	"./textures/bear.xpm"
# define WALL_XPM	"./textures/three.xpm"
# define SPACE_XPM	"./textures/green.xpm"
# define EXIT_XPM	"./textures/exit.xpm"
# define EXIT2_XPM	"./textures/exit2.xpm"
# define SPRITE_XPM	"./textures/girl.xpm"

# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_map
{
	size_t	rows;
	size_t	cols;
	size_t	cells;
	size_t	plr;
	size_t	exit;
	size_t	fish;
	size_t	moves;
	size_t	max_width;
	size_t	max_height;
	char	*field;
}	t_map;

typedef struct s_xpm
{
	void	*player;
	void	*wall;
	void	*space;
	void	*exit;
	void	*exit2;
	void	*sprite;
}	t_xpm;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	void	*mlx_plr;
	size_t	width;
	size_t	heigth;
	int		res_x;
	int		res_y;
	t_map	*map;
	t_xpm	*xpm;

}	t_mlx;

void	ft_raise_error(char *s);

void	parcer(t_map *map, int argc, char **argv);
void	init_structures(t_mlx *mlx, t_map *map);

int		open_map_file(int argc, char **argv);
void	get_map_size(t_map *map, int fd, int res);
void	write_map(t_map *map, int fd);

void	check_map_walls(t_map *map);
void	check_map_content(t_map *map);

void	draw_map(t_mlx *mlx);
void	update_sprite(t_mlx *mlx, void *sprite, size_t pos);
void	replace_exits_in_map(t_mlx *mlx);
void	update_two_cells(t_mlx *mlx, size_t old_pos, size_t new_pos);

void	run_game(t_mlx *mlx);
void	end_of_game(t_mlx *mlx);

int		key_hook(int keycode, t_mlx *mlx);
int		close_win(t_mlx *mlx);

void	init_mlx(t_mlx *mlx);
void	load_textures(t_mlx *mlx, t_xpm *xpm);
void	load_one_texture(void *mlx_inst, void **texture, char *path);
void	check_new_player_position(t_mlx *mlx, size_t new_pos);

#endif