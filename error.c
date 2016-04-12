/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 19:00:40 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/04/09 19:00:48 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		error_memory(void)
{
	ft_putstr("./fdf: Could not allocate required memory.\n");
	exit(1);
}

void		error_minilibx(void)
{
	ft_putstr("./fdf: Could not start the X11 library environment.\n");
	exit(1);
}

void		error_file(void)
{
	ft_putstr("./fdf: File is unreadable, doesn't exist or is corrupted.\n");
	exit(1);
}

void		error_argument(void)
{
	ft_putstr("./fdf: Parameters uncorrectly sized, or could not be read.\n");
	exit(1);
}

void		error_argnum(void)
{
	ft_putstr("./fdf: Too much or not enough arguments.\n");
	exit(1);
}
