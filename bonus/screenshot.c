/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   screenshot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/07/01 17:31:26 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:16:54 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_int(unsigned char *header, int value)
{
	header[0] = (unsigned char)(value);
	header[1] = (unsigned char)(value >> 8);
	header[2] = (unsigned char)(value >> 16);
	header[3] = (unsigned char)(value >> 24);
}

void	write_header(int fd, t_mother_struct *m)
{
	unsigned int		temp;
	static const int	zero[24];
	int					n;

	n = 0;
	n = write(fd, "BM\x00\x00\x00\x00\x00\x00\x00\x00", 10);
	if (n < 0)
		error_handeling(m->map, 8);
	n = write(fd, "\x36\x00\x00\x00\x28\x00\x00\x00", 8);
	if (n < 0)
		error_handeling(m->map, 8);
	temp = (unsigned int)m->map->width;
	n = write(fd, &temp, 4);
	if (n < 0)
		error_handeling(m->map, 8);
	temp = (unsigned int)m->map->height;
	n = write(fd, &temp, 4);
	if (n < 0)
		error_handeling(m->map, 8);
	n = write(fd, "\x01\x00\x18\x00", 4);
	if (n < 0)
		error_handeling(m->map, 8);
	n = write(fd, zero, 24);
	if (n < 0)
		error_handeling(m->map, 8);
}

void	put_color(t_mother_struct *m, int y, int x, int fd)
{
	int					color;
	unsigned int		rgb;
	int					n;

	n = 0;
	color = *(int*)(m->mlx->addr + (y * m->mlx->ls) + \
	(x * (m->mlx->bpp / 8)));
	rgb = (color & 0x000000FF);
	n = write(fd, &rgb, 1);
	if (n < 0)
		error_handeling(m->map, 8);
	rgb = ((color & 0x0000FF00) >> 8);
	n = write(fd, &rgb, 1);
	if (n < 0)
		error_handeling(m->map, 8);
	rgb = ((color & 0x00FF0000) >> 16);
	n = write(fd, &rgb, 1);
	if (n < 0)
		error_handeling(m->map, 8);
}

void	write_pixels(int fd, t_mother_struct *m, int y, int x)
{
	int				pad_size;
	int				n;
	unsigned int	pad;

	pad = 0;
	pad_size = (4 - (m->map->width * 3) % 4) % 4;
	while (y >= 0)
	{
		x = 0;
		while (x < m->map->width)
		{
			put_color(m, y, x, fd);
			x++;
		}
		if (pad_size > 0)
		{
			n = write(fd, "\x00\x00\x00", pad_size);
			if (n < 0)
				error_handeling(m->map, 8);
		}
		y--;
	}
}

void	make_screenshot(t_mother_struct *m)
{
	int		fd;
	int		y;
	int		x;

	x = 0;
	y = m->map->height - 1;
	fd = open("screenshot.bmp", (O_WRONLY | O_CREAT | O_TRUNC | \
	O_APPEND), 0666);
	if (fd == -1)
		error_handeling(m->map, 1);
	write_header(fd, m);
	write_pixels(fd, m, y, x);
	ft_putstr_fd("Saved screenshot as 'screenshot.bmp' in root directory.\n",\
	1, m->map);
	exit_program(m);
}
