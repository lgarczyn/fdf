/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/09 19:07:46 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/04/09 19:07:51 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			expose_hook(void *data)
{
	t_env	*env;

	env = (t_env*)data;
	mlx_put_image_to_window(env->mlx, env->win, env->img, 0, 0);
	return (0);
}

int			key_hook(int keycode, void *data)
{
	(void)data;
	if (keycode == 53)
		exit(0);
	return (0);
}

void		get_env(t_env *env, char *name)
{
	int		size;

	size = env->screen_size;
	env->mlx = mlx_init();
	if (!env->mlx)
		error_memory();
	env->win = mlx_new_window(env->mlx, size, size, name);
	if (!env->win)
		error_memory();
	env->img = mlx_new_image(env->mlx, size, size);
	if (!env->img)
		error_memory();
	env->pix = mlx_get_data_addr(env->img, &env->bpp, &env->sl, &env->end);
	env->opp = env->bpp / 8;
	mlx_expose_hook(env->win, expose_hook, env);
	mlx_key_hook(env->win, key_hook, NULL);
}
