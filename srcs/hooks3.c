/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 14:39:29 by rverscho      #+#    #+#                 */
/*   Updated: 2020/06/24 20:36:49 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate_right(t_data *data)
{
	data->dir_x_old = data->dir_x;
	data->plane_x_old = data->plane_x;
	data->dir_x = data->dir_x * cos(0.15) - data->dir_y * sin(0.15);
	data->dir_y = data->dir_x_old * sin(0.15) + data->dir_y * cos(0.15);
	data->plane_x = data->plane_x * cos(0.15) - data->plane_y * sin(0.15);
	data->plane_y = data->plane_x_old * sin(0.15) + data->plane_y * cos(0.15);
}

void	rotate_left(t_data *data)
{
	data->dir_x_old = data->dir_x;
	data->plane_x_old = data->plane_x;
	data->dir_x = data->dir_x * cos(-0.15) - data->dir_y * sin(-0.15);
	data->dir_y = data->dir_x_old * sin(-0.15) + data->dir_y * cos(-0.15);
	data->plane_x = data->plane_x * cos(-0.15) - data->plane_y * sin(-0.15);
	data->plane_y = data->plane_x_old * sin(-0.15) + data->plane_y * \
	cos(-0.15);
}

int		mouse_move(int x, int y, t_mother_struct *m)
{
	m->data->y_position -= 2 * (y - m->data->y_previous);
	m->data->y_previous = y;
	if (x < m->data->min_x)
		m->data->min_x = x;
	else if (x > m->data->max_x)
		m->data->max_x = x;
	if (x == 0)
		m->data->mouse_left = 1;
	else if (x == m->data->width - 1)
		m->data->mouse_right = 1;
	else if (x < m->data->x_previous || x == m->data->min_x)
		m->data->mouse_left = 1;
	else if (x > m->data->x_previous || x == m->data->max_x)
		m->data->mouse_right = 1;
	m->data->x_previous = x;
	return (0);
}
