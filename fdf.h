/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgarczyn <lgarczyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/10 17:08:39 by lgarczyn          #+#    #+#             */
/*   Updated: 2015/04/10 17:08:45 by lgarczyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _FDF_H
# define _FDF_H

# include <mlx.h>

# include "libft/includes/libft.h"
# include "get_next_line.h"

# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/types.h>

typedef struct			s_rawline
{
	int					len;
	char				**data;
}						t_rawline;

typedef struct			s_intline
{
	int					len;
	int					*data;
}						t_intline;

typedef struct			s_raw
{
	int					height;
	int					width;
	t_rawline			*lines;
}						t_raw;

typedef struct			s_data
{
	int					height;
	int					width;
	t_intline			*lines;
}						t_data;

typedef struct			s_coord
{
	int					x;
	int					y;
}						t_coord;

typedef struct			s_env
{
	void				*mlx;
	void				*win;
	void				*img;
	char				*pix;
	int					bpp;
	int					opp;
	int					sl;
	int					end;
	int					screen_size;
	int					screen_zoom;
	int					map_height;
}						t_env;

# define MIN(a,b)		(((a)<(b))?(a):(b))
# define MAX(a,b)		(((a)>(b))?(a):(b))

void					*xmalloc(size_t size);
int						xopen(char *name, int options);

void					display_data(t_data data, t_env env);

void					get_env(t_env *env, char *name);

void					error_file(void);
void					error_memory(void);
void					error_argnum(void);
void					error_argument(void);
void					error_minilibx(void);

#endif
