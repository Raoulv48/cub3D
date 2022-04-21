/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_textures2.c                                   :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 15:05:54 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:22:58 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	add_tex_address(t_tex *tex)
{
	tex->addr_n = mlx_get_data_addr(tex->tex_n, &tex->bpp_n, \
	&tex->ls_n, &tex->end_n);
	tex->addr_s = mlx_get_data_addr(tex->tex_s, &tex->bpp_s, \
	&tex->ls_s, &tex->end_s);
	tex->addr_e = mlx_get_data_addr(tex->tex_e, &tex->bpp_e, \
	&tex->ls_e, &tex->end_e);
	tex->addr_w = mlx_get_data_addr(tex->tex_w, &tex->bpp_w, \
	&tex->ls_w, &tex->end_w);
}

int		texture_check2(void *tex)
{
	if (tex == NULL)
		return (-1);
	return (0);
}

void	texture_check(t_mother_struct *m)
{
	m->map->fd2 = open(m->map->path_no, O_RDONLY);
	if (m->map->fd2 == -1 || texture_check2(m->tex->tex_n) == -1)
		error_handeling(m->map, 3);
	close(m->map->fd2);
	m->map->fd2 = open(m->map->path_so, O_RDONLY);
	if (m->map->fd2 == -1 || texture_check2(m->tex->tex_s) == -1)
		error_handeling(m->map, 3);
	close(m->map->fd2);
	m->map->fd2 = open(m->map->path_ea, O_RDONLY);
	if (m->map->fd2 == -1 || texture_check2(m->tex->tex_e) == -1)
		error_handeling(m->map, 3);
	close(m->map->fd2);
	m->map->fd2 = open(m->map->path_we, O_RDONLY);
	if (m->map->fd2 == -1 || texture_check2(m->tex->tex_w) == -1)
		error_handeling(m->map, 3);
	close(m->map->fd2);
	add_tex_address(m->tex);
}
