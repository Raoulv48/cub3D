/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/16 17:40:15 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:16:56 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_floor(t_data *data)
{
	if (data->side == 0 && data->ray_x > 0)
	{
		data->floor_x_wall = data->map_x;
		data->floor_y_wall = data->map_y + data->wall_x;
	}
	else if (data->side == 0 && data->ray_x < 0)
	{
		data->floor_x_wall = data->map_x + 1.0;
		data->floor_y_wall = data->map_y + data->wall_x;
	}
	else if (data->side == 1 && data->ray_y > 0)
	{
		data->floor_x_wall = data->map_x + data->wall_x;
		data->floor_y_wall = data->map_y;
	}
	else
	{
		data->floor_x_wall = data->map_x + data->wall_x;
		data->floor_y_wall = data->map_y + 1.0;
	}
}

void	texture_position_x(t_img *img, t_tex *tex, t_data *data)
{
	if (data->wall_or == 'S')
	{
		img->tex_x = (int)(data->wall_x * (double)tex->x_s);
		return ;
	}
	if (data->wall_or == 'N')
	{
		img->tex_x = (int)(data->wall_x * (double)tex->x_n);
		return ;
	}
	if (data->wall_or == 'W')
	{
		img->tex_x = (int)(data->wall_x * (double)tex->x_w);
		return ;
	}
	if (data->wall_or == 'E')
		img->tex_x = (int)(data->wall_x * (double)tex->x_e);
}

void	texture_position_y(t_img *img, t_tex *tex, t_data *data)
{
	texture_position_x(img, tex, data);
	if (data->wall_or == 'S')
		img->step = 1.0 * tex->y_s / img->line_height;
	else if (data->wall_or == 'N')
		img->step = 1.0 * tex->y_n / img->line_height;
	else if (data->wall_or == 'W')
		img->step = 1.0 * tex->y_w / img->line_height;
	else if (data->wall_or == 'E')
		img->step = 1.0 * tex->y_e / img->line_height;
	img->tex_pos = (img->draw_start - data->y_position - \
	(img->wall_height / 2) + \
	(img->line_height / 2)) * img->step;
	set_floor(data);
}

int		color_distance(int color, t_data *data)
{
	int		r;
	int		g;
	int		b;
	double	multi;

	r = (color >> 16) & 255;
	g = (color >> 8) & 255;
	b = color & 255;
	multi = 0.85 * (data->dist_wall[data->x] / 10);
	if (multi > 0.85)
		multi = 0.85;
	r = (int)(multi * 10 + ((1 - multi) * r));
	g = (int)(multi * 10 + ((1 - multi) * g));
	b = (int)(multi * 10 + ((1 - multi) * b));
	return ((r & 0xff) << 16) + ((g & 0xff) << 8) + (b & 0xff);
}
