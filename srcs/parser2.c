/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser2.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/06/24 14:42:44 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:22:13 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_resolution(t_map *map)
{
	if (map->line[map->line_i] == 'R')
		map->line_i++;
	while (map->line[map->line_i] == ' ')
		map->line_i++;
	if (map->line[map->line_i] == '-')
		error_handeling(map, 7);
	map->width = ft_atoi(map->line, map);
	while (map->line[map->line_i] == ' ')
		map->line_i++;
	map->height = ft_atoi(map->line, map);
	if (map->height == 0 || map->width == 0 || map->line[map->line_i] != '\n')
		error_handeling(map, 7);
	if ((map->width > 2560 || map->height > 1315 || map->width <= -1 \
		|| map->height <= -1) && map->screenshot != 1)
		mlx_get_screen_size(mlx_init(), &map->width, &map->height);
	ft_newline(map);
}

int		set_color2(t_map *m)
{
	int	counter;

	counter = 0;
	m->r = ft_atoi(m->line, m);
	if (m->line[m->line_i] == ',')
	{
		m->line_i++;
		counter++;
	}
	m->g = ft_atoi(m->line, m);
	if (m->line[m->line_i] == ',')
	{
		m->line_i++;
		counter++;
	}
	m->b = ft_atoi(m->line, m);
	if (counter != 2)
		error_handeling(m, 9);
	if ((m->r < 0 || m->r > 255) || (m->g < 0 || m->g > 255) || (m->b < 0 || \
	m->b > 255))
		error_handeling(m, 10);
	ft_newline(m);
	return ((m->r << 16) + (m->g << 8) + m->b);
}

int		is_color2(t_map *m, int i)
{
	if ((m->line[i] >= '0' && m->line[i] <= '9') && (m->line[i + 1] >= '0' && \
	m->line[i + 1] <= '9') && (m->line[i + 2] >= '0' && m->line[i + 2] <= '9') \
	&& ((m->line[i + 3] == ',') || (m->line[i + 3] == '\n')))
		return (4);
	if ((m->line[i] >= '0' && m->line[i] <= '9') && (m->line[i + 1] >= '0' && \
	m->line[i + 1] <= '9') && ((m->line[i + 2] == ',') || (m->line[i + 2] == \
	'\n')))
		return (3);
	if ((m->line[i] >= '0' && m->line[i] <= '9') && ((m->line[i + 1] == ',') ||\
	(m->line[i + 1] == '\n')))
		return (2);
	return (0);
}

int		is_color(t_map *m)
{
	int	i;

	i = m->line_i;
	i = i + is_color2(m, i);
	i = i + is_color2(m, i);
	i = i + is_color2(m, i);
	if (m->line[i - 1] == '\n')
		return (1);
	return (0);
}

int		set_color(t_map *m, char cf)
{
	m->fo_true = (cf == 'F') ? 1 : m->fo_true;
	m->ce_true = (cf == 'C') ? 1 : m->ce_true;
	remove_start(m);
	if (is_color(m) == 1)
		return (set_color2(m));
	else
	{
		m->path_fo = (cf == 'F') ? find_path(m, m->path_fo) : m->path_fo;
		m->path_ce = (cf == 'C') ? find_path(m, m->path_ce) : m->path_ce;
	}
	return (0);
}
