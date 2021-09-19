/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:36:13 by alchrist          #+#    #+#             */
/*   Updated: 2021/09/19 19:36:56 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int	result;
	int	i;

	i = 0;
	*line = malloc(BUFFER_SIZE);
	if (!line)
		return (-1);
	while (i < BUFFER_SIZE
		&& (result = read(fd, *line + i, CONTENT_MIN_SIZE)))
	{
		if (result == -1)
			return (-1);
		if ((*line)[i] == '\n')
			break ;
		i++;
	}
	(*line)[i] = 0;
	return (result);
}
