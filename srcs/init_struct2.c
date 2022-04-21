/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   init_struct2.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/18 14:33:44 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 17:56:15 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_tex3(t_tex *tex)
{
	tex->tex_spr = 0;
	tex->addr_spr = 0;
	tex->bpp_spr = 0;
	tex->ls_spr = 0;
	tex->end_spr = 0;
	tex->y_spr = 0;
	tex->x_spr = 0;
}

void	init_tex2(t_tex *tex)
{
	tex->tex_w = 0;
	tex->addr_w = 0;
	tex->bpp_w = 0;
	tex->ls_w = 0;
	tex->end_w = 0;
	tex->y_w = 0;
	tex->x_w = 0;
	tex->tex_fo = 0;
	tex->addr_fo = 0;
	tex->bpp_fo = 0;
	tex->ls_fo = 0;
	tex->end_fo = 0;
	tex->y_fo = 0;
	tex->x_fo = 0;
	tex->tex_ce = 0;
	tex->addr_ce = 0;
	tex->bpp_ce = 0;
	tex->ls_ce = 0;
	tex->end_ce = 0;
	tex->y_ce = 0;
	tex->x_ce = 0;
	init_tex3(tex);
}

t_tex	init_tex(void)
{
	t_tex tex;

	tex.tex_n = 0;
	tex.addr_n = 0;
	tex.bpp_n = 0;
	tex.ls_n = 0;
	tex.end_n = 0;
	tex.y_n = 0;
	tex.x_n = 0;
	tex.tex_e = 0;
	tex.addr_e = 0;
	tex.bpp_e = 0;
	tex.ls_e = 0;
	tex.end_e = 0;
	tex.y_e = 0;
	tex.x_e = 0;
	tex.tex_s = 0;
	tex.addr_s = 0;
	tex.bpp_s = 0;
	tex.ls_s = 0;
	tex.end_s = 0;
	tex.y_s = 0;
	tex.x_s = 0;
	init_tex2(&tex);
	return (tex);
}

t_spr	init_spr(void)
{
	t_spr spr;

	spr.sprite = 0;
	spr.distance = 0;
	spr.sprite_x = 0;
	spr.sprite_y = 0;
	spr.inv = 0;
	spr.transform_x = 0;
	spr.transform_y = 0;
	spr.screen_x = 0;
	spr.height = 0;
	spr.width = 0;
	spr.start_y = 0;
	spr.end_y = 0;
	spr.start_x = 0;
	spr.end_x = 0;
	spr.amount = 0;
	spr.stripe = 0;
	spr.tex_x = 0;
	spr.tex_y = 0;
	return (spr);
}

t_img	init_img(void)
{
	t_img		img;

	img.line_height = 0;
	img.draw_start = 0;
	img.draw_end = 0;
	img.wall_height = 0;
	img.tex_x = 0;
	img.tex_y = 0;
	img.step = 0;
	img.tex_pos = 0;
	return (img);
}
