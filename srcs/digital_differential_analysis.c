/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   digital_differential_analysis.c                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 19:16:04 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:17:36 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	step(t_data *data)
{
	if (data->ray_x < 0)
	{
		data->step_x = -1;
		data->dist_x = (data->spawnx - data->map_x) * data->delta_x;
	}
	else
	{
		data->step_x = 1;
		data->dist_x = (data->map_x + 1.0 - data->spawnx) * data->delta_x;
	}
	if (data->ray_y < 0)
	{
		data->step_y = -1;
		data->dist_y = (data->spawny - data->map_y) * data->delta_y;
	}
	else
	{
		data->step_y = 1;
		data->dist_y = (data->map_y + 1.0 - data->spawny) * data->delta_y;
	}
}

void	step_map(t_data *data, t_map *map)
{
	if (map->map[data->map_y][data->map_x] == 1)
		data->hit = 1;
	if (data->dist_x < data->dist_y)
	{
		data->dist_x += data->delta_x;
		data->map_x += data->step_x;
		data->side = 0;
	}
	else
	{
		data->dist_y += data->delta_y;
		data->map_y += data->step_y;
		data->side = 1;
	}
	if (map->map[data->map_y][data->map_x] == 1)
		data->hit = 1;
}

void	wall(t_data *data)
{
	if (data->side == 0)
	{
		data->dist_wall[data->x] = (data->map_x - data->spawnx + \
		(1.0 - data->step_x) / 2) / data->ray_x;
		data->wall_x = data->spawny + data->dist_wall[data->x] * data->ray_y;
		data->wall_or = (data->ray_x < 0) ? 'E' : 'W';
	}
	else
	{
		data->dist_wall[data->x] = (data->map_y - data->spawny + \
		(1.0 - data->step_y) / 2) / data->ray_y;
		data->wall_x = data->spawnx + data->dist_wall[data->x] * data->ray_x;
		data->wall_or = (data->ray_y < 0) ? 'S' : 'N';
	}
	data->wall_x = data->wall_x - floor(data->wall_x);
}

void	dd_analysis(t_map *map, t_data *data)
{
	data->cam_x = 2 * data->x / (double)map->width - 1;
	data->ray_x = data->dir_x + (data->plane_x * data->cam_x);
	data->ray_y = data->dir_y + (data->plane_y * data->cam_x);
	data->delta_x = fabs(1 / data->ray_x);
	data->delta_y = fabs(1 / data->ray_y);
	data->map_x = (int)data->spawnx;
	data->map_y = (int)data->spawny;
	step(data);
	data->hit = 0;
	while (data->hit == 0)
		step_map(data, map);
	wall(data);
}

void	set_image(t_data *data, t_img *img)
{
	img->wall_height = data->height;
	if (data->side == 0)
		data->dist_wall[data->x] = (data->map_x - data->spawnx +\
		(1 - data->step_x) / 2) / data->ray_x;
	else
		data->dist_wall[data->x] = (data->map_y - data->spawny +\
		(1 - data->step_y) / 2) / data->ray_y;
	img->line_height = ((int)(img->wall_height /\
	data->dist_wall[data->x]));
	img->draw_start = -(img->line_height / 2) + (img->wall_height / 2);
	img->draw_start += data->y_position;
	if (img->draw_start > data->height)
		img->draw_start = data->height;
	if (img->draw_start < 0)
		img->draw_start = 0;
	img->draw_end = (img->line_height / 2) + (img->wall_height / 2);
	img->draw_end += data->y_position;
	if (img->draw_end > data->height)
		img->draw_end = data->height - 1;
	if (img->draw_end < 0)
		img->draw_end = 0;
}
