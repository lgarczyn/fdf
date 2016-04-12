/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 17:07:58 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/04/10 17:08:00 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		read_args(t_env *env, int ac, char **av)
{
	if (ac < 2 || ac > 5)
		error_argnum();
	if (ac > 2)
		env->screen_size = ft_atoi(av[2]);
	else
		env->screen_size = 500;
	if (ac > 3)
		env->screen_zoom = ft_atoi(av[3]);
	else
		env->screen_zoom = 10;
	if (ac > 4)
		env->map_height = ft_atoi(av[4]);
	else
		env->map_height = 10;
	if (env->screen_size < 10 || env->screen_zoom < 0)
		error_argument();
}

t_data		read_raw(t_raw raw)
{
	t_data	data;
	int		i;
	int		j;

	i = 0;
	data.height = raw.height;
	data.width = raw.width;
	data.lines = xmalloc(data.height * sizeof(t_intline));
	while (i < data.height)
	{
		j = 0;
		data.lines[i].len = raw.lines[i].len;
		data.lines[i].data = xmalloc(data.lines[i].len * sizeof(int*));
		while (j < data.lines[i].len)
		{
			data.lines[i].data[j] = ft_atoi(raw.lines[i].data[j]);
			j++;
		}
		i++;
	}
	return (data);
}

t_raw		read_file(int fd)
{
	char	*text;
	t_raw	raw;
	int		er;
	int		len;
	int		size;

	len = 0;
	size = 100000;
	raw.lines = xmalloc(size * sizeof(t_rawline*));
	raw.width = 0;
	while ((er = get_next_line(fd, &text)) > 0)
	{
		raw.lines[len].data = ft_strsplit(text, ' ');
		if (!raw.lines[len].data)
			error_memory();
		raw.lines[len].len = ft_tablen(raw.lines[len].data);
		raw.width = MAX(raw.width, raw.lines[len].len);
		if (++len == size)
			error_file();
		free(text);
	}
	if (er < 0)
		error_file();
	raw.height = len;
	return (raw);
}

int			main(int ac, char **av)
{
	int		fd;
	t_raw	raw;
	t_data	data;
	t_env	env;

	read_args(&env, ac, av);
	get_env(&env, av[1]);
	fd = xopen(av[1], O_RDONLY);
	raw = read_file(fd);
	close(fd);
	data = read_raw(raw);
	display_data(data, env);
	mlx_loop(env.mlx);
	return (1);
}
