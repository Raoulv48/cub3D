/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/26 19:24:22 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/14 18:16:11 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	game(t_mlx *mlx, t_mother_struct *m)
{
	if (m->map->screenshot == 0)
	{
		mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, m->data->width,\
		m->data->height, "cub3d");
		mlx_hook(mlx->mlx_win, 2, 1L << 0, key_pres, m);
		mlx_hook(mlx->mlx_win, 3, 1L << 1, key_release, m);
		mlx_hook(mlx->mlx_win, 17, 0, exit_program, m);
		mlx_hook(mlx->mlx_win, 4, 1L << 2, mouse_down, m);
		mlx_hook(mlx->mlx_win, 5, 1L << 3, mouse_release, m);
		mlx_hook(mlx->mlx_win, 6, 1L << 6, mouse_move, m);
	}
	mlx_loop_hook(mlx->mlx_ptr, &image, m);
	system("afplay soundtrack.mp3 &");
	mlx_loop(mlx->mlx_ptr);
}

void	run(t_mother_struct *m)
{
	t_mlx mlx;
	t_img img;
	t_tex tex;

	mlx = init_mlx();
	img = init_img();
	mlx.mlx_ptr = mlx_init();
	tex = init_tex();
	m->mlx = &mlx;
	m->img = &img;
	m->tex = &tex;
	fill_textures(m, &tex);
	mlx_mouse_hide();
	game(m->mlx, m);
}

int		save_check(char *av)
{
	if (av[0] != '-' || av[1] != '-')
		return (-1);
	if (av[2] != 's')
		return (-1);
	if (av[3] != 'a')
		return (-1);
	if (av[4] != 'v')
		return (-1);
	if (av[5] != 'e')
		return (-1);
	if (av[6] != '\0')
		return (-1);
	return (0);
}

int		main(int ac, char **av)
{
	t_mother_struct	m;
	t_map			map;
	t_data			data;
	t_spr			spr;

	if (ac == 0 || (ac >= 3 && save_check(av[2]) == -1))
		error_handeling(&map, 1);
	map = initialize_map();
	if (ac == 3 && save_check(av[2]) == 0)
		map.screenshot = 1;
	parser(&map, av[1]);
	data = init_data(&map);
	m.map = &map;
	m.data = &data;
	spr = init_spr();
	m.spr = &spr;
	fill_sprite(&m);
	run(&m);
}
