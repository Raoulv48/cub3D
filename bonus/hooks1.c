/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   hooks1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/11 15:59:06 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/14 19:09:32 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

#define ESC 53
#define FWD 13
#define BWD 1
#define STR_L 0
#define STR_R 2
#define STR_UP 126
#define STR_DOWN 125
#define ROT_L 123
#define ROT_R 124
#define MOUSE_D 1

int		exit_program(t_mother_struct *m)
{
	ft_putstr_fd("Program will be closed...\n", 1, m->map);
	system("killall afplay");
	exit(1);
	return (0);
}

int		key_pres(int keycode, t_mother_struct *m)
{
	if (keycode == ESC)
		exit_program(m);
	if (keycode == FWD && m->data->bwd != 1)
		m->data->fwd = 1;
	if (keycode == BWD && m->data->fwd != 1)
		m->data->bwd = 1;
	if (keycode == STR_L && m->data->rght != 1)
		m->data->lft = 1;
	if (keycode == STR_R && m->data->lft != 1)
		m->data->rght = 1;
	if (keycode == ROT_L && m->data->rot_r != 1)
		m->data->rot_l = 1;
	if (keycode == ROT_R && m->data->rot_l != 1)
		m->data->rot_r = 1;
	if (keycode == STR_UP)
		m->data->y_position = m->data->y_position + 30;
	if (keycode == STR_DOWN)
		m->data->y_position = m->data->y_position - 30;
	return (0);
}

int		key_release(int keycode, t_mother_struct *m)
{
	if (keycode == FWD)
		m->data->fwd = 0;
	if (keycode == BWD)
		m->data->bwd = 0;
	if (keycode == STR_L)
		m->data->lft = 0;
	if (keycode == STR_R)
		m->data->rght = 0;
	if (keycode == ROT_L)
		m->data->rot_l = 0;
	if (keycode == ROT_R)
		m->data->rot_r = 0;
	return (0);
}

int		mouse_down(int button, int x, int y, t_mother_struct *m)
{
	if (button == MOUSE_D)
		m->data->mouse_down = 1;
	x = 0;
	y = 0;
	return (0);
}

int		mouse_release(int button, int x, int y, t_mother_struct *m)
{
	if (button == MOUSE_D)
		m->data->mouse_down = 0;
	x = 0;
	y = 0;
	return (0);
}
