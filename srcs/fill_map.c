/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fill_map.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/31 20:55:16 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:22:33 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_max_width(t_map *map)
{
	int	max;
	int i;

	max = 0;
	i = map->line_i;
	while (map->line[i] != '\0')
	{
		while (map->line[i] != '\n' && map->line[i] != '\0')
		{
			max++;
			i++;
		}
		if (map->line[i] == '\n')
		{
			if (max > map->map_maxx)
				map->map_maxx = max;
			i++;
			max = 0;
		}
	}
}

void	count_n(t_map *map, int set)
{
	int i;

	i = map->line_i;
	if (set == 1)
	{
		while (map->line[i] != '\0')
		{
			if (map->line[i] == '\n')
				map->map_y++;
			i++;
			if (map->line[i - 1] == '\n' && map->line[i] == '\n')
				break ;
		}
	}
	if (set == 2)
	{
		map->map_xwidth = 0;
		while (map->line[i] != '\n' && map->line[i] != '\0')
		{
			map->map_xwidth++;
			i++;
		}
	}
}

void	map_malloc(t_map *map, int set)
{
	if (set == 1)
	{
		count_n(map, 1);
		if (map->map_y > 0)
			map->map_y++;
		map->map = (int**)malloc(sizeof(int*) * map->map_y);
		map->cmap = (int**)malloc(sizeof(int*) * map->map_y);
		map->map_width = (int*)malloc(sizeof(int) * map->map_y);
	}
	if (set == 2)
	{
		count_n(map, 2);
		map->map[map->map_x] = (int*)malloc(sizeof(int) *\
		map->map_maxx);
		map->cmap[map->map_x] = (int*)malloc(sizeof(int) *\
		map->map_maxx);
		map->map_x++;
		map->map_width[map->map_index] = map->map_xwidth;
	}
}

void	fill_map(t_map *map, int j, int k)
{
	while (map->map_index < map->map_y)
	{
		j = 0;
		map_malloc(map, 2);
		while (j < map->map_xwidth)
		{
			map->line[k] = (map->line[k] == ' ') ? '0' : map->line[k];
			map->cmap[map->map_index][j] = ft_atoi_char(map->line[k]);
			map->map[map->map_index][j] = ft_atoi_char(map->line[k]);
			is_player(map->line[k], map, map->map_index, j);
			j++;
			k++;
		}
		if (map->line[k] == '\n')
			k++;
		while (j < map->map_maxx)
		{
			map->cmap[map->map_index][j] = 0;
			j++;
		}
		map->line_i = k;
		map->map_index++;
		if (map->line[k - 1] == '\n' && map->line[k] == '\n')
			break ;
	}
}

void	create_map(t_map *map)
{
	int	j;
	int	k;

	get_max_width(map);
	map_malloc(map, 1);
	j = 0;
	k = map->line_i;
	fill_map(map, j, k);
	if (map->pos_true == 0)
		error_handeling(map, 2);
	j = 0;
	if (map->line[map->line_i - 1] == '\n' && map->line[map->line_i] == '\n')
	{
		map->map[map->map_x] = (int*)malloc(sizeof(int) *\
		map->map_maxx);
		map->cmap[map->map_x] = (int*)malloc(sizeof(int) *\
		map->map_maxx);
		while (j < map->map_xwidth)
		{
			map->cmap[map->map_index][j] = 0;
			map->map[map->map_index][j] = 0;
			j++;
		}
	}
	check_map(map);
}
