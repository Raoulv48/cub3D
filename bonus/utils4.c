/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils4.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/03/09 19:43:35 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/14 17:26:01 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		xpm_or_png(char *path)
{
	int		i;
	char	p1;
	char	p2;
	char	p3;

	i = 0;
	while (path[i + 3] != '\0')
		i++;
	p1 = path[i];
	p2 = path[i + 1];
	p3 = path[i + 2];
	if (p1 == 'x' && p2 == 'p' && p3 == 'm')
		return (1);
	if (p1 == 'p' && p2 == 'n' && p3 == 'g')
		return (2);
	return (0);
}

int		get_end_path(char *path, t_map *map)
{
	while ((path[map->line_i - 3] != 'x' || path[map->line_i - 2] != 'p' || \
	path[map->line_i - 1] != 'm') && (path[map->line_i - 3] != 'p' || \
	path[map->line_i - 2] != 'n' || path[map->line_i - 1] != 'g') && \
	(path[map->line_i] != '\n' && path[map->line_i] != '\0'))
		map->line_i++;
	if (path[map->line_i] != '\n')
		error_handeling(map, 3);
	return (map->line_i);
}
