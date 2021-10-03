/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:13:37 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/03 17:13:38 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define CONTENT_MIN_SIZE 1
# define BUFFER_SIZE 1024

# include <stdlib.h>
# include <unistd.h>

int		get_next_line(int fd, char **line);

#endif