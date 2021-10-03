/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcer_load_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 16:55:00 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/02 22:04:04 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
**		@brief		open correct map file and return its fd
*/
int	open_map_file(int argc, char **argv)
{
	int	len_fname;
	int	fd;

	if (argc != 2)
		ft_raise_error("Incorrect arguments, need only one");
	len_fname = ft_strlen(argv[1]);
	if (len_fname < 4 || ft_strncmp(argv[1] + (len_fname - 4), ".ber", 5))
		ft_raise_error("Incorrect map name, need <map_name.ber>");
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_raise_error(0);
	return (fd);
}

/*
**		@brief		Get the map size (rows and cols)		
*/
void	get_map_size(t_map *map, int fd, int res)
{
	char	*line;
	bool	last_line;

	line = NULL;
	last_line = false;
	while (res)
	{
		res = get_next_line(fd, &line);
		if (res < 0)
			ft_raise_error(0);
		if (ft_strlen(line) > map->max_width)
			ft_raise_error("Too long width line in map for this resolution");
		if (!map->cols)
			map->cols = ft_strlen(line);
		if (!ft_strlen(line))
			last_line = true;
		if (ft_strlen(line) && (last_line || map->cols != ft_strlen(line)))
			ft_raise_error("Different line lenghts in the map");
		map->rows += !last_line;
		if (map->rows > map->max_height)
			ft_raise_error("Too tall map for this resolution");
		free(line);
	}
	close(fd);
}

/*
**		@brief		writes map from file to structure (char array)
**		
*/
void	write_map(t_map *map, int fd)
{
	size_t	i;
	char	*line;

	map->cells = map->rows * map->cols;
	map->field = malloc(sizeof(*map->field) * map->cells);
	if (!map->field)
		ft_raise_error(0);
	i = 0;
	while (i < map->rows)
	{
		get_next_line(fd, &line);
		ft_memcpy(map->field + i * map->cols, line, map->cols);
		free(line);
		i++;
	}
	close(fd);
}
