/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:35:56 by alchrist          #+#    #+#             */
/*   Updated: 2021/09/19 19:33:39 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

# include <fcntl.h> 

# include <stdbool.h>
# include <stdio.h>
# include <sys/errno.h>

# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

# define MAX_WIDTH	64
# define MAX_HEIGHT	32

typedef struct s_map
{
	size_t	rows;
	size_t	cols;
	size_t	cells;
	size_t	plr;
	size_t	exit;
	size_t	fish;
	char	*field;
	
}	t_map;


void	ft_raise_error(char *s);

void	parcer(t_map *map, int argc, char **argv);
void	init_map_structure(t_map *map);
int		open_map_file(int argc, char **argv);
void	get_map_size(t_map *map, int fd, int res);
void	write_map(t_map *map, int fd);

void	check_map_walls(t_map *map);
void	check_map_content(t_map *map);





#endif