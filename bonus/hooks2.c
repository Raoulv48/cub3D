/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/17 17:37:00 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:16:58 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	move_forward(t_data *data, t_map *map)
{
	if (data->rght || data->lft)
	{
		if (map->map[(int)(data->spawny)][(int)(data->spawnx +\
		data->dir_x * 0.33)] == 0)
			data->spawnx += data->dir_x * 0.2;
		if (map->map[(int)(data->spawny + data->dir_y * 0.33)]\
		[(int)(data->spawnx)] == 0)
			data->spawny += data->dir_y * 0.2;
	}
	else
	{
		if (map->map[(int)(data->spawny)][(int)(data->spawnx + data->dir_x\
		* 0.33)] == 0)
			data->spawnx += data->dir_x * 0.2;
		if (map->map[(int)(data->spawny + data->dir_y * 0.33)][(int)\
		(data->spawnx)] == 0)
			data->spawny += data->dir_y * 0.2;
	}
}

void	move_backward(t_data *data, t_map *map)
{
	if (data->rght || data->lft)
	{
		if (map->map[(int)(data->spawny)][(int)(data->spawnx - data->dir_x\
		* 0.33)] == 0)
			data->spawnx = data->spawnx - data->dir_x * 0.2;
		if (map->map[(int)(data->spawny - data->dir_y * 0.33)]\
		[(int)(data->spawnx)] == 0)
			data->spawny = data->spawny - data->dir_y * 0.2;
	}
	else
	{
		if (map->map[(int)(data->spawny)][(int)(data->spawnx - data->dir_x\
		* 0.33)] == 0)
			data->spawnx = data->spawnx - data->dir_x * 0.2;
		if (map->map[(int)(data->spawny - data->dir_y * 0.33)]\
		[(int)(data->spawnx)] == 0)
			data->spawny = data->spawny - data->dir_y * 0.2;
	}
}

void	move_right(t_data *data, t_map *map)
{
	if (data->fwd || data->bwd)
	{
		if (map->map[(int)(data->spawny)][(int)(data->spawnx +\
		(data->plane_x * 0.33))] == 0)
			data->spawnx = data->spawnx + data->plane_x * 0.2;
		if (map->map[(int)(data->spawny + data->plane_y * 0.33)]\
		[(int)(data->spawnx)] == 0)
			data->spawny = data->spawny + data->plane_y * 0.2;
	}
	else
	{
		if (map->map[(int)(data->spawny)][(int)(data->spawnx +\
		(data->plane_x * 0.33))] == 0)
			data->spawnx = data->spawnx + data->plane_x * 0.2;
		if (map->map[(int)(data->spawny + data->plane_y * 0.33)]\
		[(int)(data->spawnx)] == 0)
			data->spawny = data->spawny + data->plane_y * 0.2;
	}
}

void	move_left(t_data *data, t_map *map)
{
	if (data->fwd || data->bwd)
	{
		if (map->map[(int)(data->spawny)][(int)(data->spawnx -\
		(data->plane_x * 0.33))] == 0)
			data->spawnx = data->spawnx - data->plane_x * 0.2;
		if (map->map[(int)(data->spawny - data->plane_y * 0.33)]\
		[(int)(data->spawnx)] == 0)
			data->spawny = data->spawny - data->plane_y * 0.2;
	}
	else
	{
		if (map->map[(int)(data->spawny)][(int)(data->spawnx -\
		(data->plane_x * 0.33))] == 0)
			data->spawnx = data->spawnx - data->plane_x * 0.2;
		if (map->map[(int)(data->spawny - data->plane_y * 0.33)]\
		[(int)(data->spawnx)] == 0)
			data->spawny = data->spawny - data->plane_y * 0.2;
	}
}

void	move_hook(t_mother_struct *m)
{
	if (m->data->fwd)
		move_forward(m->data, m->map);
	if (m->data->bwd)
		move_backward(m->data, m->map);
	if (m->data->rght)
		move_right(m->data, m->map);
	if (m->data->lft)
		move_left(m->data, m->map);
	if (m->data->rot_r || m->data->mouse_right)
		rotate_right(m->data);
	if (m->data->rot_l || m->data->mouse_left)
		rotate_left(m->data);
	m->data->mouse_right = 0;
	m->data->mouse_left = 0;
}
