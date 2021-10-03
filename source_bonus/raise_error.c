/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raise_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alchrist <alchrist@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/19 19:35:23 by alchrist          #+#    #+#             */
/*   Updated: 2021/10/02 22:04:04 by alchrist         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

/*
**	@brief	raises error message and exit from program
**	
**	@param	s	pointer to string with error message
*/
void	ft_raise_error(char *s)
{
	ft_putstr_fd("Error\n", 2);
	if (s)
		ft_putendl_fd(s, 2);
	else
		perror(NULL);
	exit (1);
}
