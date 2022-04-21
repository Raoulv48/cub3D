/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_textures.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:28:06 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:17:00 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	fill_sprite_texture(t_mother_struct *m, t_tex *tex)
{
	m->map->fd2 = open(m->map->path_sprite, O_RDONLY);
	if (m->map->fd2 == -1)
		error_handeling(m->map, 3);
	close(m->map->fd2);
	if (xpm_or_png(m->map->path_sprite) == 1)
		tex->tex_spr = mlx_xpm_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_sprite, &tex->x_spr, &tex->y_spr);
	else
		tex->tex_spr = mlx_png_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_sprite, &tex->x_spr, &tex->y_spr);
	if (texture_check2(m->tex->tex_spr) == -1)
		error_handeling(m->map, 3);
	tex->addr_spr = mlx_get_data_addr(tex->tex_spr, &tex->bpp_spr, \
	&tex->ls_spr, &tex->end_spr);
}

void	fill_floor_ceiling2(t_mother_struct *m, t_tex *tex)
{
	if (m->map->ce_true == 1 && m->map->path_ce != NULL)
	{
		m->map->fd2 = open(m->map->path_ce, O_RDONLY);
		if (m->map->fd2 == -1)
			error_handeling(m->map, 3);
		close(m->map->fd2);
		if (xpm_or_png(m->map->path_ce) == 1)
			tex->tex_ce = mlx_xpm_file_to_image(m->mlx->mlx_ptr,\
			m->map->path_ce, &tex->x_ce, &tex->y_ce);
		else
			tex->tex_ce = mlx_png_file_to_image(m->mlx->mlx_ptr,\
			m->map->path_ce, &tex->x_ce, &tex->y_ce);
		if (texture_check2(m->tex->tex_ce) == -1)
			error_handeling(m->map, 3);
		tex->addr_ce = mlx_get_data_addr(tex->tex_ce, &tex->bpp_ce, \
		&tex->ls_ce, &tex->end_ce);
	}
}

void	fill_floor_ceiling(t_mother_struct *m, t_tex *tex)
{
	if (m->map->fo_true == 1 && m->map->path_fo != NULL)
	{
		m->map->fd2 = open(m->map->path_fo, O_RDONLY);
		if (m->map->fd2 == -1)
			error_handeling(m->map, 3);
		close(m->map->fd2);
		if (xpm_or_png(m->map->path_fo) == 1)
			tex->tex_fo = mlx_xpm_file_to_image(m->mlx->mlx_ptr,\
			m->map->path_fo, &tex->x_fo, &tex->y_fo);
		else
			tex->tex_fo = mlx_png_file_to_image(m->mlx->mlx_ptr,\
			m->map->path_fo, &tex->x_fo, &tex->y_fo);
		if (texture_check2(m->tex->tex_fo) == -1)
			error_handeling(m->map, 3);
		tex->addr_fo = mlx_get_data_addr(tex->tex_fo, &tex->bpp_fo, \
		&tex->ls_fo, &tex->end_fo);
	}
	fill_floor_ceiling2(m, m->tex);
}

void	fill_textures2(t_mother_struct *m, t_tex *tex)
{
	if (xpm_or_png(m->map->path_ea) == 1)
		tex->tex_e = mlx_xpm_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_ea, &tex->x_e, &tex->y_e);
	else
		tex->tex_e = mlx_png_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_ea, &tex->x_e, &tex->y_e);
	if (xpm_or_png(m->map->path_we) == 1)
		tex->tex_w = mlx_xpm_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_we, &tex->x_w, &tex->y_w);
	else
		tex->tex_w = mlx_png_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_we, &tex->x_w, &tex->y_w);
}

void	fill_textures(t_mother_struct *m, t_tex *tex)
{
	if (xpm_or_png(m->map->path_no) == 1)
		tex->tex_n = mlx_xpm_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_no, &tex->x_n, &tex->y_n);
	else
		tex->tex_n = mlx_png_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_no, &tex->x_n, &tex->y_n);
	if (xpm_or_png(m->map->path_so) == 1)
		tex->tex_s = mlx_xpm_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_so, &tex->x_s, &tex->y_s);
	else if (mlx_png_file_to_image(m->mlx->mlx_ptr, m->map->path_so,\
	&tex->x_s, &tex->y_s) != NULL)
		tex->tex_s = mlx_png_file_to_image(m->mlx->mlx_ptr,\
		m->map->path_so, &tex->x_s, &tex->y_s);
	else
		error_handeling(m->map, 1);
	fill_textures2(m, tex);
	fill_floor_ceiling(m, m->tex);
	fill_sprite_texture(m, m->tex);
	texture_check(m);
}
