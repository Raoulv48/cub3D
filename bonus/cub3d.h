/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   cub3d.h                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: rverscho <rverscho@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/01/26 19:13:16 by rverscho      #+#    #+#                 */
/*   Updated: 2020/07/29 18:02:51 by rverscho      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include "../minilibmlx/mlx.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>

typedef struct		s_spr
{
	double			**sprite;
	double			*distance;
	double			sprite_x;
	double			sprite_y;
	double			inv;
	double			transform_x;
	double			transform_y;
	int				screen_x;
	int				height;
	int				width;
	int				start_y;
	int				end_y;
	int				start_x;
	int				end_x;
	int				amount;
	int				stripe;
	int				tex_x;
	int				tex_y;
	int				i;
}					t_spr;

typedef struct		s_map
{
	int				width;
	int				height;
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	char			*path_sprite;
	int				floor_color;
	int				ceiling_color;
	int				fo_color_bool;
	int				ce_color_bool;
	int				**map;
	int				**cmap;
	int				fd;
	char			*line;
	char			*resl;
	int				line_i;
	int				map_index;
	int				*map_width;
	int				map_y;
	int				map_x;
	int				map_xwidth;
	int				map_maxx;
	int				error;
	int				c;
	int				spawnx;
	int				spawny;
	int				px;
	int				py;
	double			plane_x;
	double			plane_y;
	int				mi;
	int				mj;
	char			*path_fo;
	int				fo_true;
	char			*path_ce;
	int				ce_true;
	int				fd2;
	int				pos_true;
	int				r;
	int				g;
	int				b;
	int				screenshot;
}					t_map;

typedef struct		s_data
{
	double			spawnx;
	double			spawny;
	double			dir_x;
	double			dir_y;
	double			plane_x;
	double			plane_y;
	double			cam_x;
	double			ray_x;
	double			ray_y;
	int				map_x;
	int				map_y;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	double			dist_x;
	double			dist_y;
	double			delta_x;
	double			delta_y;
	double			*dist_wall;
	int				x;
	int				y;
	double			wall_x;
	int				wall_or;
	int				width;
	int				height;
	int				fwd;
	int				bwd;
	int				rght;
	int				lft;
	int				rot_r;
	int				rot_l;
	double			dir_x_old;
	double			plane_x_old;
	double			dir_y_old;
	double			plane_y_old;
	double			floor_x_wall;
	double			floor_y_wall;
	double			weight;
	double			current_dist;
	double			current_x;
	double			current_y;
	int				tex_x_floor;
	int				tex_y_floor;
	int				tex_x_ceiling;
	int				tex_y_ceiling;
	int				mouse_down;
	int				mouse_release;
	int				mouse_move;
	int				mouse_left;
	int				mouse_right;
	int				x_previous;
	int				y_previous;
	int				min_x;
	int				min_y;
	int				max_x;
	int				max_y;
	int				up;
	int				down;
	int				y_position;
	double			horizon;
	double			cur_row;
	int				spritepos;
}					t_data;

typedef struct		s_tex
{
	void			*tex_n;
	char			*addr_n;
	int				bpp_n;
	int				ls_n;
	int				end_n;
	int				y_n;
	int				x_n;
	void			*tex_e;
	char			*addr_e;
	int				bpp_e;
	int				ls_e;
	int				end_e;
	int				y_e;
	int				x_e;
	void			*tex_s;
	char			*addr_s;
	int				bpp_s;
	int				ls_s;
	int				end_s;
	int				y_s;
	int				x_s;
	void			*tex_w;
	char			*addr_w;
	int				bpp_w;
	int				ls_w;
	int				end_w;
	int				y_w;
	int				x_w;
	void			*tex_fo;
	char			*addr_fo;
	int				bpp_fo;
	int				ls_fo;
	int				end_fo;
	int				y_fo;
	int				x_fo;
	void			*tex_ce;
	char			*addr_ce;
	int				bpp_ce;
	int				ls_ce;
	int				end_ce;
	int				y_ce;
	int				x_ce;
	void			*tex_spr;
	char			*addr_spr;
	int				bpp_spr;
	int				ls_spr;
	int				end_spr;
	int				y_spr;
	int				x_spr;
}					t_tex;

typedef struct		s_img
{
	int				line_height;
	int				draw_start;
	int				draw_end;
	int				wall_height;
	int				tex_x;
	int				tex_y;
	double			step;
	double			tex_pos;
}					t_img;

typedef struct		s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*img_new;
	void			*img_old;
	char			*addr;
	int				bpp;
	int				ls;
	int				end;
	int				render;
}					t_mlx;

typedef struct		s_mother_struct
{
	t_spr			*spr;
	t_map			*map;
	t_mlx			*mlx;
	t_data			*data;
	t_img			*img;
	t_tex			*tex;
}					t_mother_struct;

/*
**init_struct
*/
t_map				initialize_map();
t_data				init_data(t_map *map);
t_mlx				init_mlx();
t_img				init_img();
t_tex				init_tex();
t_spr				init_spr(void);

/*
**main and mapparsing
*/
void				parser(t_map *map, char *file);
void				get_parser_string(int fd, t_map *map);
void				remove_start(t_map *map);
int					struct_check(t_map *map);
char				*find_path(t_map *map, char *str);
size_t				ft_newline(t_map *map);
int					ft_strnlen(t_map *map);
size_t				int_len_str(const char *str, int i);
void				is_player(char c, t_map *map, int i, int j);
int					set_color(t_map *m, char cf);
void				set_resolution(t_map *map);
void				set_spawn(char c, t_map *map);

/*
**check map
*/
void				check_map(t_map *map);

/*
**fill map
*/
void				create_map(t_map *map);

/*
**fill textures and calculate
*/
void				fill_textures(t_mother_struct *m, t_tex *tex);
void				texture_check(t_mother_struct *m);
int					color_distance(int color, t_data *data);
void				texture_position_y(t_img *img, t_tex *tex, t_data *data);
void				texture_position_x(t_img *img, t_tex *tex, t_data *data);
int					xpm_or_png(char *path);
int					get_end_path(char *path, t_map *map);
int					texture_check2(void *tex);

/*
**digital_differential_analysis and calculations
*/
void				dd_analysis(t_map *map, t_data *data);
void				set_image(t_data *data, t_img *img);

/*
**image
*/
int					image(t_mother_struct *m);
void				get_pixel_floor(t_mother_struct *m, int i);
void				get_pixel_floor_ceiling(t_mother_struct *m, int i);
void				make_screenshot(t_mother_struct *m);

/*
**hooks and keys
*/
int					key_pres(int keycode, t_mother_struct *m);
int					key_release(int keycode, t_mother_struct *m);
int					mouse_down(int button, int x, int y, t_mother_struct *m);
int					mouse_move(int x, int y, t_mother_struct *m);
int					mouse_release(int button, int x, int y, t_mother_struct *m);
int					exit_program(t_mother_struct *m);

/*
**movement
*/
void				move_hook(t_mother_struct *m);
void				move_forward(t_data *data, t_map *map);
void				move_backward(t_data *data, t_map *map);
void				move_right(t_data *data, t_map *map);
void				move_left(t_data *data, t_map *map);
void				rotate_right(t_data *data);
void				rotate_left(t_data *data);

/*
**sprite
*/
void				fill_sprite(t_mother_struct *m);
void				draw_sprite(t_mother_struct *m);
void				set_sprite_image(t_mother_struct *m, int i);

/*
**utils
*/
size_t				str_len(const char *str);
int					int_len_int(unsigned int n);
int					find_space(char *str, int i);
int					ft_atoi(const char *str, t_map *map);
char				*ft_strcat(char *origin, char *append, t_map *map);
char				*ft_substr(char *s, unsigned int start, size_t len,\
					t_map *map);
void				ft_putstr_fd(char *s, int fd, t_map *map);
int					ft_atoi_char(char c);

/*
**error handeling
*/
void				error_handeling(t_map *map, int set);

#endif
