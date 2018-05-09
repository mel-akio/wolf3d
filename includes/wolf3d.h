/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   wolf3d.h                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 13:39:43 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/30 11:40:05 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef _WOLF3D_H
# define _WOLF3D_H

# define WIDTH 800
# define LENGHT 600
# define KEY_LEFT 123
# define KEY_UP 126
# define KEY_RIGHT 124
# define KEY_DOWN 125
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_R 15
# define KEY_G 5
# define KEY_S 1
# define KEY_ESC 53
# define MOUSE_LEFT 1
# define MOUSE_RIGHT 2
# define MOUSE_CENTER 3
# define SCROLL_UP 5
# define SCROLL_DOWN 4
# define KEY_ESC 53
# define KEY_M 46
# define KEY_J 38
# define KEY_B 11
# define KEY_J 38
# define KEY_LESS 78
# define KEY_MORE 69
# define KEY_ASTERISK 67
# define KEY_PRESS_MASK (1L<<0)
# define KEY_PRESS 2
# define BLOCK_SIZE 10
# define VIEW_DISTANCE 500
# define FOV 150
# define ITER 200

# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <math.h>

typedef struct		s_coor
{
	int x;
	int y;
	int z;
}					t_coor;

typedef struct		s_var
{
	int				i;
	int				j;
	int				c;
	int				x;
	int				col;
}					t_var;

typedef struct		s_size
{
	int width;
	int lenght;
}					t_size;

typedef struct		s_angle
{
	float			cosin;
	float			sinus;
	float			degres;
	unsigned int	texture_col;
}					t_angle;

typedef struct		s_img
{
	void			*ptr;
	char			*data;
	int				sizeline;
	int				bpp;
	int				endian;
}					t_img;

typedef struct		s_object
{
	int				sprite_id;
	int				distance;
	int				position;
}					t_object;

typedef struct		s_param
{
	t_img			background;
	t_img			display;
	t_img			wall;
	t_img			gun;
	t_img			monster;
	t_img			crosshair;
	t_img			menu;
	t_img			post_traitment;
	int				wall_dir[ITER];
	void			*mlx;
	void			*win;
	t_coor			*map;
	float			pl_x;
	float			pl_y;
	int				l_x;
	int				l_y;
	t_coor			angle;
	int				direction;
	int				dist[500];
	int				mid_dist;
	int				color[500];
	int				i[3];
	int				iter;
	float			degres;
	t_angle			*angles;
	char			side;
	t_img			minimap;
	int				width;
	int				height;
	float			move_foward;
	float			move_back;
	t_size			size_map;
	t_size			textures_size;
	int				*wall_colors;
	int				ray_n;
	int				iter_n;
	t_object		*object;
	float			motion;
	int				hide_map;
}					t_param;

void				var_init(t_param *param);
t_coor				*convert_int(char ***str, t_param param);
t_coor				*make_map(char **str, t_param *param, t_coor size);
int					key_event(int keycode, t_param *param);
void				put_map(t_param par, t_param *ptr_par);
void				put_player(t_param *par, t_param *ptr_par);
void				put_square(t_coor pos, t_param *ptr_par, int color);
float				draw_line(t_coor val1, t_coor val2, t_param param, t_param
*ptr_par);
float				draw_line2(t_coor val1, t_coor val2, t_param param, t_param
*ptr_par);
t_coor				map_size(char *name);
unsigned int		rgb(unsigned char r, unsigned char g, unsigned char b);
int					check_map(char ***map);
int					usage(int argc);
void				direction(t_param *par);
int					check_grid(unsigned int x, unsigned int y, t_param *par);
void				calc_wall(t_param par, int dist, t_param *ptr_par);
float				distance(float x1, float y1, float x2, float y2);
void				ft_setpx(int *img, int x, int y, int color);
void				make_mask(t_param *param, t_img *img, char xpm[255],
t_size size);
void				rotate(t_param *par, int n);
void				collision(t_param *param, int keycode);
void				collision2(t_param *param, int keycode);
char				side_check(t_param par);
void				skybox(t_param *param, int x, int y);
void				ft_setpx_2(int *img, t_coor coor, int color, t_size size);
void				texture_in_tab(t_param *param);
void				texture_position(unsigned int x, unsigned int y, t_param
*param);
unsigned int		ft_shader(int	color, unsigned int distance);
void				make_ground(t_img *img);
void				print_objects(t_param *param);
void				shoot(t_param *param);
void				refresh_screen(t_param *param);
void				textures_init(t_param *param);
int					step_x1(t_coor p1, t_coor p2, int *x, t_param *ptr_par);
int					step_x2(t_coor p1, t_coor p2, int *x, t_param *ptr_par);
int					step_y1(t_coor p1, t_coor p2, int *y, t_param *ptr_par);
int					step_y2(t_coor p1, t_coor p2, int *y, t_param *ptr_par);
void				show_wall(t_param par, t_param *ptr, int dist, t_var v);
void				ray_cast(t_var v, t_param *par, t_param *ptr_par,
t_coor player);
void				exit_game(t_param *param);
void				free_line(char **tab);
void				show_menu(t_param *param);
int					secure(char *path);
t_coor				*close_map(t_coor *map, t_param *param);
int					side_wall(t_param *param, int x, int y);
void				color_fix(t_param *param);

#endif
