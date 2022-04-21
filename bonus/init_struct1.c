/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_struct1.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/26 19:46:41 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 17:55:56 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map2(t_map *map)
{
	map->fd2 = 0;
	map->fo_true = 0;
	map->ce_true = 0;
	map->pos_true = 0;
	map->r = 0;
	map->g = 0;
	map->b = 0;
	map->map_maxx = 0;
	map->screenshot = 0;
}

t_map	initialize_map(void)
{
	t_map map;

	map.width = 0;
	map.height = 0;
	map.path_no = NULL;
	map.path_so = NULL;
	map.path_we = NULL;
	map.path_ea = NULL;
	map.path_fo = NULL;
	map.path_ce = NULL;
	map.path_sprite = NULL;
	map.floor_color = 0;
	map.ceiling_color = 0;
	map.map = 0;
	map.map_index = 0;
	map.map_width = 0;
	map.map_xwidth = 0;
	map.fd = 0;
	map.line = NULL;
	map.line_i = 0;
	map.error = 0;
	init_map2(&map);
	return (map);
}

void	init_data2(t_data *data)
{
	data->dist_x = 0;
	data->delta_x = 0;
	data->delta_y = 0;
	data->step_x = 0;
	data->step_y = 0;
	data->hit = 0;
	data->fwd = 0;
	data->bwd = 0;
	data->rght = 0;
	data->lft = 0;
	data->rot_r = 0;
	data->rot_l = 0;
	data->mouse_down = 0;
	data->mouse_release = 0;
	data->mouse_move = 0;
	data->mouse_right = 0;
	data->mouse_left = 0;
	data->up = 0;
	data->down = 0;
	data->y_position = 0;
}

t_data	init_data(t_map *map)
{
	t_data data;

	data.height = map->height;
	data.width = map->width;
	data.spawnx = (double)map->spawnx + 0.5;
	data.spawny = (double)map->spawny + 0.5;
	data.dir_x = map->px;
	data.dir_y = map->py;
	data.plane_x = map->plane_x;
	data.plane_y = map->plane_y;
	data.dist_wall = (double*)malloc(sizeof(double) * map->width);
	data.x = 0;
	data.y = 0;
	data.side = 0;
	data.wall_x = 0;
	data.ray_x = 0;
	data.ray_y = 0;
	data.cam_x = 0;
	data.map_y = 0;
	data.map_x = 0;
	data.dist_y = 0;
	init_data2(&data);
	return (data);
}

t_mlx	init_mlx(void)
{
	t_mlx	mlx;

	mlx.mlx_ptr = 0;
	mlx.mlx_win = 0;
	mlx.img_new = 0;
	mlx.img_old = 0;
	mlx.addr = 0;
	mlx.bpp = 0;
	mlx.ls = 0;
	mlx.end = 0;
	mlx.render = 1;
	return (mlx);
}
