/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_sprite.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/08 15:07:57 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:22:01 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	sprite_counter(t_map *map, t_spr *spr)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < map->map_y)
	{
		while (x < map->map_width[y])
		{
			if (map->map[y][x] == 2)
				spr->amount++;
			x++;
		}
		x = 0;
		y++;
	}
}

void	malloc_sprite(t_mother_struct *m, int amount)
{
	int i;

	i = 0;
	m->spr->sprite = (double**)malloc(sizeof(double*) * amount);
	if (!m->spr->sprite)
		error_handeling(m->map, 4);
	while (i < amount)
	{
		m->spr->sprite[i] = (double*)malloc(sizeof(double) * 2);
		if (!m->spr->sprite[i])
			error_handeling(m->map, 4);
		i++;
	}
	m->spr->distance = (double*)malloc(sizeof(double) * amount);
	if (!m->spr->distance)
		error_handeling(m->map, 4);
}

void	sprite_location(t_map *map, t_spr *spr)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (y < map->map_y)
	{
		while (x < map->map_width[y])
		{
			if (map->map[y][x] == 2)
			{
				spr->sprite[i][0] = y + 0.5;
				spr->sprite[i][1] = x + 0.5;
				i++;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	fill_sprite(t_mother_struct *m)
{
	sprite_counter(m->map, m->spr);
	if (m->spr->amount == 0)
		return ;
	malloc_sprite(m, m->spr->amount);
	sprite_location(m->map, m->spr);
}
