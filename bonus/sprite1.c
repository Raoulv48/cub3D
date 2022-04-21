/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sprite1.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 14:14:10 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:16:53 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	calculate_distance(t_spr *spr, t_data *data, int i)
{
	spr->distance[i] = ((data->spawnx - spr->sprite[i][1]) * \
	(data->spawnx - spr->sprite[i][1])) + ((data->spawny - \
	spr->sprite[i][0]) * (data->spawny - spr->sprite[i][0]));
}

void	sort_sprite(t_spr *spr)
{
	double	y_tmp;
	double	x_tmp;
	double	dis_tmp;
	int		i;
	int		counter;

	i = 0;
	while (i < spr->amount - 1)
	{
		counter = 0;
		if (spr->distance[i] < spr->distance[i + 1])
		{
			y_tmp = spr->sprite[i + 1][0];
			x_tmp = spr->sprite[i + 1][1];
			dis_tmp = spr->distance[i + 1];
			spr->distance[i + 1] = spr->distance[i];
			spr->sprite[i + 1][0] = spr->sprite[i][0];
			spr->sprite[i + 1][1] = spr->sprite[i][1];
			spr->distance[i] = dis_tmp;
			spr->sprite[i][0] = y_tmp;
			spr->sprite[i][1] = x_tmp;
			counter++;
		}
		i = (counter != 0) ? 0 : i + 1;
	}
}

void	calculate_sprite(t_spr *spr, t_data *data, int i)
{
	data->spritepos = data->y_position;
	spr->sprite_x = spr->sprite[i][1] - data->spawnx;
	spr->sprite_y = spr->sprite[i][0] - data->spawny;
	spr->inv = 1.0 / (data->plane_x * data->dir_y - data->dir_x *\
	data->plane_y);
	spr->transform_x = spr->inv * (data->dir_y * spr->sprite_x -\
	data->dir_x * spr->sprite_y);
	spr->transform_y = spr->inv * (-data->plane_y * spr->sprite_x +\
	data->plane_x * spr->sprite_y);
	spr->screen_x = (int)((data->width / 2) * (1 + spr->transform_x /\
	spr->transform_y));
	spr->height = abs((int)(data->height / (spr->transform_y)));
	spr->start_y = -spr->height / 2 + data->height / 2 + data->spritepos;
	if (spr->start_y < 0)
		spr->start_y = 0;
	spr->end_y = spr->height / 2 + data->height / 2 + data->spritepos;
	if (spr->end_y >= data->height)
		spr->end_y = data->height - 1;
	spr->width = abs((int)(data->height / (spr->transform_y)));
	spr->start_x = -spr->width / 2 + spr->screen_x;
	if (spr->start_x < 0)
		spr->start_x = 0;
	spr->end_x = spr->width / 2 + spr->screen_x;
	if (spr->end_x >= data->width)
		spr->end_x = data->width - 1;
}

void	draw_sprite(t_mother_struct *m)
{
	int i;

	i = 0;
	while (i < m->spr->amount)
	{
		calculate_distance(m->spr, m->data, i);
		i++;
	}
	sort_sprite(m->spr);
	i = 0;
	while (i < m->spr->amount)
	{
		calculate_sprite(m->spr, m->data, i);
		set_sprite_image(m, i);
		i++;
	}
}
