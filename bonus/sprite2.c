/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 18:22:18 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:16:51 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		color_distance_sprite(int color, t_spr *spr, int i)
{
	int		r;
	int		g;
	int		b;
	double	multi;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	multi = 0.55 * (spr->distance[i] / 25);
	if (multi > 0.85)
		multi = 0.90;
	r = (int)(multi * 10 + ((1 - multi) * r));
	g = (int)(multi * 10 + ((1 - multi) * g));
	b = (int)(multi * 10 + ((1 - multi) * b));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}

void	put_pixel_sprite(t_mother_struct *m, int y, int i)
{
	int		d;
	int		color;

	d = ((y - m->data->spritepos) * 256) - m->map->height * 128 + \
	m->spr->height * 128;
	m->spr->tex_y = (d * m->tex->y_spr) / m->spr->height / 256;
	color = *(int*)(m->tex->addr_spr + (m->spr->tex_y * m->tex->ls_spr +\
	m->spr->tex_x * (m->tex->bpp_spr / 8)));
	if (color > 0)
	{
		*(int*)(m->mlx->addr + (y * m->mlx->ls) + (m->spr->stripe *\
		(m->mlx->bpp / 8))) = color_distance_sprite(color, m->spr, i);
	}
}

void	set_sprite_image(t_mother_struct *m, int i)
{
	int y;

	m->spr->stripe = m->spr->start_x;
	while (m->spr->stripe < m->spr->end_x)
	{
		m->spr->tex_x = (int)(256 * (m->spr->stripe - (-m->spr->width / 2 +\
		m->spr->screen_x)) * m->tex->x_spr / m->spr->width) / 256;
		y = m->spr->start_y;
		if (m->spr->transform_y > 0 && m->spr->stripe > 0 && m->spr->stripe <\
		m->data->width && m->spr->transform_y <\
		m->data->dist_wall[m->spr->stripe])
		{
			while (y < m->spr->end_y)
			{
				put_pixel_sprite(m, y, i);
				y++;
			}
		}
		m->spr->stripe++;
	}
}
