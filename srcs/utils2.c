/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils2.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 17:55:11 by rverscho      #+#    #+#                 */
/*   Updated: 2020/06/03 18:38:13 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

size_t	str_len(const char *str)
{
	size_t	i;

	i = 0;
	if (str[i] == '\0')
		return (i);
	while (str[i] != '\0')
		i++;
	return (i);
}

int		ft_strnlen(t_map *map)
{
	int	i;

	i = map->line_i;
	if (map->line[i] == '\0')
		return (i);
	while (map->line[i] != '\n')
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd, t_map *map)
{
	int		i;
	char	c;

	i = 0;
	if (s != 0)
	{
		while (s[i] != '\0' && map->error != -1)
		{
			c = s[i];
			map->error = write(fd, &c, 1);
			i++;
		}
		if (map->error == -1)
			error_handeling(map, 1);
	}
}

size_t	int_len_str(const char *str, int i)
{
	size_t	len;
	int		start;

	start = i;
	len = 0;
	if (str[i] == '\0')
		return (i);
	while (str[i] != '\0' && i < start + 14)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			len++;
		}
		i++;
	}
	return (len);
}

void	is_player(char c, t_map *map, int i, int j)
{
	if (map->pos_true == 1 && (c == 'N' || c == 'E' || c == 'S' || c == 'W'))
		error_handeling(map, 5);
	if (c == 'N' || c == 'E' || c == 'S' || c == 'W')
	{
		map->spawny = i;
		map->spawnx = j;
		set_spawn(c, map);
		map->pos_true = 1;
	}
}
