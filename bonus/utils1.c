/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils1.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 14:01:07 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/02 16:06:26 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static char	*strcathelp(char *dest, char *origin, char *append, t_map *map)
{
	map->mi = 0;
	map->mj = 0;
	while (origin[map->mj] != '\0')
	{
		dest[map->mi] = origin[map->mj];
		map->mi++;
		map->mj++;
	}
	map->mj = 0;
	while (append[map->mj] != '\0')
	{
		dest[map->mi] = append[map->mj];
		map->mi++;
		map->mj++;
	}
	dest[map->mi] = '\0';
	return (dest);
}

char		*ft_strcat(char *origin, char *append, t_map *map)
{
	int		x;
	char	*dest;

	x = str_len(origin) + str_len(append);
	dest = (char*)malloc(sizeof(char) * (x + 1));
	if (!dest)
	{
		free(origin);
		free(append);
		error_handeling(map, 1);
	}
	dest = strcathelp(dest, origin, append, map);
	free(origin);
	free(append);
	return (dest);
}

char		*ft_substr(char *s, unsigned int start, size_t len, t_map *map)
{
	char	*substr;
	size_t	i;

	substr = malloc(sizeof(char) * (len) + 1);
	if (!substr)
	{
		free(s);
		error_handeling(map, 1);
	}
	i = 0;
	while (start < len && s[start])
	{
		substr[i] = s[start];
		i++;
		start++;
	}
	substr[i] = '\0';
	return (substr);
}

void		set_spawn(char c, t_map *map)
{
	if (c == 'S')
	{
		map->py = 1;
		map->plane_x = -0.66;
		map->plane_y = 0;
	}
	if (c == 'E')
	{
		map->px = 1;
		map->plane_y = 0.66;
		map->plane_x = 0;
	}
	if (c == 'N')
	{
		map->py = -1;
		map->plane_x = 0.66;
		map->plane_y = 0;
	}
	if (c == 'W')
	{
		map->px = -1;
		map->plane_y = -0.66;
		map->plane_x = 0;
	}
}
