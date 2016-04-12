/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrapper.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 19:12:26 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/04/09 19:12:27 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		*xmalloc(size_t size)
{
	void	*alloc;

	alloc = malloc(size);
	if (!alloc)
		error_memory();
	return (alloc);
}

int			xopen(char *name, int options)
{
	int		fd;

	if (!name)
		error_file();
	fd = open(name, options);
	if (fd < 0)
		error_file();
	return (fd);
}
