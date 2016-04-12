/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 19:01:00 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/04/09 19:01:02 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		pixel_put(t_env env, int x, int y)
{
	int		pos;

	if (x < 0 || x >= env.screen_size || y < 0 || y >= env.screen_size)
		return ;
	pos = (env.sl * y) + (x * env.opp);
	env.pix[pos] = 0xFF;
	env.pix[pos + 1] = 0xFF;
	env.pix[pos + 2] = 0xFF;
}

void		ft_line(t_coord a, t_coord b, t_env env)
{
	t_coord	d;
	t_coord	s;
	t_coord	e;

	d.x = abs(b.x - a.x);
	s.x = a.x < b.x ? 1 : -1;
	d.y = abs(b.y - a.y);
	s.y = a.y < b.y ? 1 : -1;
	e.x = (d.x > d.y ? d.x : -d.y) / 2;
	while (1)
	{
		pixel_put(env, a.x, a.y);
		if (a.x == b.x && a.y == b.y)
			break ;
		e.y = e.x;
		if (e.y > -d.x)
			e.x -= d.y, a.x += s.x;
		if (e.y < d.y)
			e.x += d.x, a.y += s.y;
	}
}

t_coord		get_coord(t_coord p, t_coord dim, int d, t_env env)
{
	int		px;
	int		py;

	py = (p.y - dim.y / 2) * env.screen_zoom;
	px = (p.x - dim.x / 2) * env.screen_zoom;
	px += py / 2;
	py -= px / 8;
	py += env.screen_size / 2;
	px += env.screen_size / 2;
	py -= d * env.map_height;
	return ((t_coord){px, py});
}

void		display_knot(int x, int y, t_data data, t_env env)
{
	t_coord	p1;
	t_coord	p2;
	t_coord	dim;

	dim = (t_coord){data.width, data.height};
	p1 = (t_coord){x, y};
	p1 = get_coord(p1, dim, data.lines[y].data[x], env);
	pixel_put(env, p1.x, p1.y);
	if (x > 0)
	{
		p2 = (t_coord){x - 1, y};
		p2 = get_coord(p2, dim, data.lines[y].data[x - 1], env);
		ft_line(p1, p2, env);
	}
	if (y && x < data.lines[y - 1].len)
	{
		p2 = (t_coord){x, y - 1};
		p2 = get_coord(p2, dim, data.lines[y - 1].data[x], env);
		ft_line(p1, p2, env);
	}
}

void		display_data(t_data data, t_env env)
{
	int		x;
	int		y;

	y = -1;
	while (++y < data.height)
	{
		x = -1;
		while (++x < data.lines[y].len)
			display_knot(x, y, data, env);
	}
}
