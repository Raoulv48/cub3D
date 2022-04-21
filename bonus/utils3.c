/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   utils3.c                                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/27 16:56:24 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/09 21:01:03 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error_handeling(t_map *map, int set)
{
	if (set == 1)
		ft_putstr_fd("an error has occured\n", 1, map);
	if (set == 2)
		ft_putstr_fd("an invalid map has been found!\n", 1, map);
	if (set == 3)
		ft_putstr_fd("an invalid texture has been found!\n", 1, map);
	if (set == 4)
		ft_putstr_fd("an invalid sprite has been found!\n", 1, map);
	if (set == 5)
		ft_putstr_fd("multiple spawn positions found!\n", 1, map);
	if (set == 6)
		ft_putstr_fd("wrong indentifier has been found!\n", 1, map);
	if (set == 7)
		ft_putstr_fd("invald resolution has been found!\n", 1, map);
	if (set == 8)
		ft_putstr_fd("screenshot has broken while writing!\n", 1, map);
	if (set == 9)
		ft_putstr_fd("an invalid cub file has been used!\n", 1, map);
	if (set == 10)
		ft_putstr_fd("an invalid color has been used!\n", 1, map);
	exit(0);
}

int		int_len_int(unsigned int n)
{
	int	i;

	i = 0;
	while (n >= 10)
	{
		n = n / 10;
		i++;
	}
	if (n >= 1 && n <= 9)
		i++;
	return (i);
}

int		find_space(char *str, int i)
{
	while (str[i] != '\0' && str[i - 1] != ' ')
		i++;
	return (i);
}

int		ft_atoi(const char *str, t_map *map)
{
	long	result;

	result = 0;
	while (str[map->line_i] >= '0' && str[map->line_i] <= '9')
	{
		if (result >= 922337203685477580)
		{
			result = (result * 10) + (str[map->line_i] - '0');
			return ((int)result);
		}
		result = (result * 10) + (str[map->line_i] - '0');
		map->line_i++;
	}
	return ((int)result);
}

int		ft_atoi_char(char c)
{
	int	result;

	result = 0;
	if (c != '\0')
	{
		if (c >= '0' && c <= '2')
		{
			result = (result * 10) + (c - '0');
			return (result);
		}
		if (c == 'N' || c == 'W' || c == 'E' || c == 'S')
			return (c);
	}
	return (9);
}
