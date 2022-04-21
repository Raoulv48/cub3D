/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_parser_string.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/30 17:39:44 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/09 20:59:36 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	ft_newline(t_map *map)
{
	int i;

	i = map->line_i;
	while (map->line[i] != '\n')
	{
		i++;
		if (map->line[i] == '\0')
			return (0);
	}
	while (map->line[i] == '\n')
		i++;
	return (map->line_i = i);
}

void	get_parser_string(int fd, t_map *map)
{
	char	*buff;
	int		nbytes;

	if (fd < 0)
		error_handeling(map, 1);
	map->line = malloc(sizeof(char) + 1);
	if (map->line == NULL)
		error_handeling(map, 1);
	map->line[0] = '\0';
	nbytes = 1;
	while (nbytes != 0 && map->error != -1)
	{
		buff = malloc(sizeof(char) * 64 + 1);
		if (buff == NULL)
			error_handeling(map, 1);
		nbytes = read(fd, buff, 64);
		buff[nbytes] = '\0';
		if (nbytes == 0)
			break ;
		if (nbytes == -1)
			error_handeling(map, 1);
		map->line = ft_strcat(map->line, buff, map);
	}
	free(buff);
}

void	remove_start(t_map *map)
{
	while (map->line[map->line_i] == 'R' || map->line[map->line_i] == 'N' || \
	map->line[map->line_i] == 'O' || map->line[map->line_i] == 'S' || \
	map->line[map->line_i] == 'E' || map->line[map->line_i] == 'A' || \
	map->line[map->line_i] == 'W' || map->line[map->line_i] == 'F' || \
	map->line[map->line_i] == 'C')
		map->line_i++;
	while (map->line[map->line_i] == ' ')
		map->line_i++;
}

char	*find_path(t_map *map, char *str)
{
	char	*tmp;
	int		c;

	if (str == NULL)
	{
		tmp = NULL;
		c = 0;
		remove_start(map);
		tmp = ft_substr(map->line, map->line_i, get_end_path(map->line, map), \
		map);
		ft_newline(map);
		map->fd2 = open(tmp, O_RDONLY);
		if (map->fd2 == -1)
			error_handeling(map, 3);
		close(map->fd2);
		map->fd2 = 0;
		return (tmp);
	}
	else
		error_handeling(map, 6);
	return (NULL);
}

int		struct_check(t_map *map)
{
	if (map->path_no == NULL || map->path_ea == NULL || map->path_so ==\
	NULL || map->path_we == NULL || (map->fo_true == 0 && map->floor_color\
	== 0) || (map->ce_true == 0 && map->ceiling_color == 0))
		return (0);
	return (1);
}
