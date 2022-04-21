/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/03 14:53:01 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:16:55 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		color_distance_fc(int color, t_data *data)
{
	int		r;
	int		g;
	int		b;
	double	multi;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	multi = 0.85 * (data->current_dist / 3);
	if (multi > 0.85)
		multi = 0.85;
	r = (int)(multi * 10 + ((1 - multi) * r));
	g = (int)(multi * 10 + ((1 - multi) * g));
	b = (int)(multi * 10 + ((1 - multi) * b));
	color = ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	set_pixel_floor(t_mother_struct *m, int i)
{
	if (i > m->img->draw_start)
	{
		if (m->map->fo_true == 1 && m->map->path_fo != NULL)
		{
			m->data->tex_x_floor = (int)(m->data->current_x * \
			m->tex->x_fo) % m->tex->x_fo;
			m->data->tex_y_floor = (int)(m->data->current_y * \
			m->tex->y_fo) % m->tex->y_fo;
			m->map->floor_color = *(int*)(m->tex->addr_fo + \
			(m->data->tex_y_floor * m->tex->ls_fo + m->data->tex_x_floor * \
			(m->tex->bpp_fo / 8)));
		}
		*(int*)(m->mlx->addr + (i * m->mlx->ls) + (m->data->x *\
		(m->mlx->bpp / 8))) = color_distance_fc(m->map->floor_color, m->data);
	}
}

void	set_pixel_ceiling(t_mother_struct *m, int i)
{
	if (i < m->img->draw_start)
	{
		if (m->map->ce_true == 1 && m->map->path_ce != NULL)
		{
			m->data->tex_x_ceiling = (int)(m->data->current_x * \
			m->tex->x_ce) % m->tex->x_ce;
			m->data->tex_y_ceiling = (int)(m->data->current_y * \
			m->tex->y_ce) % m->tex->y_ce;
			m->map->ceiling_color = *(int*)(m->tex->addr_ce + \
			(m->data->tex_y_ceiling * m->tex->ls_ce + m->data->tex_x_ceiling * \
			(m->tex->bpp_ce / 8)));
		}
		*(int*)(m->mlx->addr + (i * m->mlx->ls) + (m->data->x *\
		(m->mlx->bpp / 8))) = color_distance_fc(m->map->ceiling_color, m->data);
	}
}

void	get_pixel_floor_ceiling(t_mother_struct *m, int i)
{
	m->data->horizon = m->data->height / 2;
	m->data->cur_row = i - (m->data->height / 2 + m->data->y_position);
	if (i < m->data->horizon + m->data->y_position)
		m->data->current_dist = 0 - m->data->horizon / m->data->cur_row;
	else
		m->data->current_dist = m->data->horizon / m->data->cur_row;
	m->data->weight = m->data->current_dist \
	/ m->data->dist_wall[m->data->x];
	m->data->current_x = m->data->weight * \
	m->data->floor_x_wall + (1.0 - m->data->weight) * \
	m->data->spawnx;
	m->data->current_y = m->data->weight * \
	m->data->floor_y_wall + (1.0 - m->data->weight) * \
	m->data->spawny;
	set_pixel_ceiling(m, i);
	set_pixel_floor(m, i);
}
