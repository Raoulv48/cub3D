/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   check_map.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/02/02 15:05:12 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:17:22 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floodfill(int x, int y, int **cmap, t_map *map)
{
	if (y == map->map_y - 1 || x == map->map_width[y] - 1 || y == 0 || x == 0 \
	|| map->map[y][x] == 9)
		error_handeling(map, 2);
	if (cmap[y][x] == 0 || cmap[y][x] == 2 || cmap[y][x] == 9)
	{
		cmap[y][x] = 'X';
		if (cmap[y + 1][x] != 1)
			floodfill(x, y + 1, cmap, map);
		if (cmap[y - 1][x] != 1)
			floodfill(x, y - 1, cmap, map);
		if (cmap[y][x + 1] != 1)
			floodfill(x + 1, y, cmap, map);
		if (cmap[y][x - 1] != 1)
			floodfill(x - 1, y, cmap, map);
		if (cmap[y + 1][x + 1] != 1)
			floodfill(x + 1, y + 1, cmap, map);
		if (cmap[y - 1][x - 1] != 1)
			floodfill(x - 1, y - 1, cmap, map);
		if (cmap[y + 1][x - 1] != 1)
			floodfill(x - 1, y + 1, cmap, map);
		if (cmap[y - 1][x + 1] != 1)
			floodfill(x + 1, y - 1, cmap, map);
	}
}

void	check_map(t_map *map)
{
	int i;
	int j;

	i = map->spawny;
	j = map->spawnx;
	map->map[i][j] = 0;
	map->cmap[i][j] = 0;
	floodfill(j, i, map->cmap, map);
}
