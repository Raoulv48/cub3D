/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   parser.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 15:15:43 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:19:46 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	find_bad_identifier(t_map *map)
{
	if (map->line[map->line_i] == 'R' && map->line[map->line_i + 1] != ' ')
		error_handeling(map, 6);
	if (map->line[map->line_i] == 'N' && map->line[map->line_i + 1] == 'O' && \
		map->line[map->line_i + 2] != ' ')
		error_handeling(map, 6);
	if (map->line[map->line_i] == 'S' && map->line[map->line_i + 1] == 'O' && \
		map->line[map->line_i + 2] != ' ')
		error_handeling(map, 6);
	if (map->line[map->line_i] == 'W' && map->line[map->line_i + 1] == 'E' && \
		map->line[map->line_i + 2] != ' ')
		error_handeling(map, 6);
	if (map->line[map->line_i] == 'E' && map->line[map->line_i + 1] == 'A' && \
		map->line[map->line_i + 2] != ' ')
		error_handeling(map, 6);
	if (map->line[map->line_i] == 'S' && map->line[map->line_i + 1] != ' ' && \
		map->line[map->line_i + 1] != 'S')
		error_handeling(map, 6);
	if (map->line[map->line_i] == 'F' && map->line[map->line_i + 1] == ' ')
		error_handeling(map, 6);
	if (map->line[map->line_i] == 'C' && map->line[map->line_i + 1] == ' ')
		error_handeling(map, 6);
}

int		find_identifier(t_map *map)
{
	while (map->line[map->line_i] == ' ')
		map->line_i++;
	if (map->line[map->line_i] == 'R' && map->line[map->line_i + 1] == ' ')
		return (1);
	if (map->line[map->line_i] == 'N' && map->line[map->line_i + 1] == 'O' && \
		map->line[map->line_i + 2] == ' ')
		return (2);
	if (map->line[map->line_i] == 'S' && map->line[map->line_i + 1] == 'O' && \
		map->line[map->line_i + 2] == ' ')
		return (3);
	if (map->line[map->line_i] == 'W' && map->line[map->line_i + 1] == 'E' && \
		map->line[map->line_i + 2] == ' ')
		return (4);
	if (map->line[map->line_i] == 'E' && map->line[map->line_i + 1] == 'A' && \
		map->line[map->line_i + 2] == ' ')
		return (5);
	if (map->line[map->line_i] == 'S' && map->line[map->line_i + 1] == ' ')
		return (6);
	if (map->line[map->line_i] == 'F' && map->line[map->line_i + 1] == ' ')
		return (7);
	if (map->line[map->line_i] == 'C' && map->line[map->line_i + 1] == ' ')
		return (8);
	find_bad_identifier(map);
	return (0);
}

void	set_path(t_map *map)
{
	while (struct_check(map) == 0 && map->c < 20)
	{
		if (find_identifier(map) == 1)
			set_resolution(map);
		if (find_identifier(map) == 2)
			map->path_no = find_path(map, map->path_no);
		if (find_identifier(map) == 3)
			map->path_so = find_path(map, map->path_so);
		if (find_identifier(map) == 4)
			map->path_we = find_path(map, map->path_we);
		if (find_identifier(map) == 5)
			map->path_ea = find_path(map, map->path_ea);
		if (find_identifier(map) == 6)
			map->path_sprite = find_path(map, map->path_sprite);
		if (find_identifier(map) == 7)
			map->floor_color = set_color(map, 'F');
		if (find_identifier(map) == 8)
			map->ceiling_color = set_color(map, 'C');
		if (map->line[map->line_i] == '\n')
			ft_newline(map);
		map->c++;
	}
}

void	pre_parser(t_map *map)
{
	while (map->line[map->line_i]
	!= '\0' && map->error != -1)
	{
		set_path(map);
		while (struct_check(map) == 1 && map->line[map->line_i] == '\n')
			ft_newline(map);
		create_map(map);
	}
	if (struct_check(map) == 0)
		error_handeling(map, 9);
	map->c = 0;
}

void	parser(t_map *map, char *file)
{
	map->fd = open(file, O_RDONLY);
	get_parser_string(map->fd, map);
	pre_parser(map);
	close(map->fd);
}
