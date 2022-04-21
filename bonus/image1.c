/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   image1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/14 18:35:29 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:16:57 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		get_pixel(t_mother_struct *m, int color)
{
	m->img->tex_y = (int)m->img->tex_pos;
	m->img->tex_pos = m->img->tex_pos + m->img->step;
	if (m->data->wall_or == 'S')
		color = *(int*)(m->tex->addr_s + (m->img->tex_y * \
		m->tex->ls_s) + (m->img->tex_x *\
		(m->tex->bpp_s / 8)));
	else if (m->data->wall_or == 'N')
		color = *(int*)(m->tex->addr_n + (m->img->tex_y * \
		m->tex->ls_n) + (m->img->tex_x *\
		(m->tex->bpp_n / 8)));
	else if (m->data->wall_or == 'W')
		color = *(int*)(m->tex->addr_w + (m->img->tex_y * \
		m->tex->ls_w) + (m->img->tex_x *\
		(m->tex->bpp_w / 8)));
	else if (m->data->wall_or == 'E')
		color = *(int*)(m->tex->addr_e + (m->img->tex_y * \
		m->tex->ls_e) + (m->img->tex_x *\
		(m->tex->bpp_e / 8)));
	return (color_distance(color, m->data));
}

void	build_image(t_mother_struct *m)
{
	int i;
	int color;
	int start;

	start = m->img->draw_start;
	color = 0;
	i = 0;
	while (i < start)
	{
		get_pixel_floor_ceiling(m, i);
		i++;
	}
	while (start < m->img->draw_end)
	{
		*(int*)(m->mlx->addr + (start *\
		m->mlx->ls) + (m->data->x * (m->mlx->bpp\
		/ 8))) = get_pixel(m, color);
		start++;
	}
	i = m->img->draw_end;
	while (i < m->data->height)
	{
		get_pixel_floor_ceiling(m, i);
		i++;
	}
}

void	switch_image(t_mlx *mlx)
{
	mlx->img_old = mlx->img_new;
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img_old, 0, 0);
}

void	new_image(t_mlx *mlx, t_map *map)
{
	mlx->img_new = mlx_new_image(mlx->mlx_ptr, map->width, map->height);
	if (!mlx->img_new)
		error_handeling(map, 1);
	mlx->addr = mlx_get_data_addr(mlx->img_new, &mlx->bpp, &mlx->ls, \
	&mlx->end);
}

int		image(t_mother_struct *m)
{
	if (m->mlx->img_new)
		switch_image(m->mlx);
	new_image(m->mlx, m->map);
	move_hook(m);
	while (m->data->x < m->data->width)
	{
		dd_analysis(m->map, m->data);
		set_image(m->data, m->img);
		texture_position_y(m->img, m->tex, m->data);
		build_image(m);
		m->data->x++;
	}
	if (m->spr->amount > 0)
		draw_sprite(m);
	if (m->map->screenshot == 1)
		make_screenshot(m);
	mlx_put_image_to_window(m->mlx->mlx_ptr, m->mlx->mlx_win,\
	m->mlx->img_new, 0, 0);
	if (m->mlx->img_old)
		mlx_destroy_image(m->mlx->mlx_ptr, m->mlx->img_old);
	m->data->x = 0;
	return (0);
}
