/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mlx.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 13:39:15 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 14:43:44 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				put_map(t_param par, int zoom, t_param *ptr_par)
{
	t_coor			val;
	int				i;

	i = -1;
	zoom = 0;
	ptr_par->minimap.ptr = mlx_new_image(ptr_par->mlx, par.size_map.width,
par.size_map.lenght);
	ptr_par->minimap.data = mlx_get_data_addr(ptr_par->minimap.ptr,
&ptr_par->i[0], &ptr_par->i[1], &ptr_par->i[2]);
	put_player(&par, ptr_par);
	calc_wall(par, 0, ptr_par);
	while (par.map[++i].z != -100000)
	{
		val.x = (par.map[i].x * BLOCK_SIZE);
		val.y = (par.map[i].y) * BLOCK_SIZE;
		val.z = par.map[i].z;
		put_square(val, ptr_par, 0xFF000000);
		if (val.z == 1)
			put_square(val, ptr_par, 0xAAFFFFFF);
	}
	val.x = par.pl_x;
	val.y = par.pl_y;
	if (ptr_par->hide_map > 0)
		mlx_put_image_to_window(ptr_par->mlx, ptr_par->win,
ptr_par->minimap.ptr, 60 - par.pl_x, 60 - par.pl_y);
}

void				put_square(t_coor pos, t_param *ptr_par, int color)
{
	int				i;
	int				j;
	t_coor			coor;

	j = 0;
	i = 0;
	while (i < BLOCK_SIZE)
	{
		while (j < BLOCK_SIZE)
		{
			coor.x = pos.x + j;
			coor.y = pos.y + i;
			ft_setpx_2((int*)ptr_par->minimap.data, coor, color,
ptr_par->size_map);
			j += 1;
		}
		j = 0;
		i += 2;
	}
}

void				calc_wall(t_param par, int dist, t_param *ptr)
{
	t_var			v;

	v.x = 0;
	v.c = 0;
	make_mask(ptr, &ptr->display, "backgrounds/mask.xpm", ptr->size_map);
	while (v.c != par.iter)
	{
		dist = LENGHT * 10 / (par.dist[v.c]);
		v.col = par.angles[v.c].texture_col;
		v.i = -1;
		while (++v.i < dist)
		{
			v.j = -1;
			while (++v.j < WIDTH / par.iter)
			{
				if ((v.x + v.j > 0 && v.x + v.j < WIDTH) && (LENGHT / 2 - v.i >
0 && LENGHT / 2 - v.i < LENGHT))
					show_wall(par, ptr, dist, v);
			}
		}
		v.x += WIDTH / par.iter;
		v.c++;
	}
	mlx_put_image_to_window(ptr->mlx, ptr->win, ptr->display.ptr, 0, 0);
}

void				show_wall(t_param par, t_param *ptr, int dist, t_var v)
{
	int color;

	color = 0;
	if (ptr->wall_dir[(v.x + v.j) / 4] == 5)
		color = rgb(0, 0, 10);
	else if (ptr->wall_dir[(v.x + v.j) / 4] == 10)
		color = rgb(5, 0, 0);
	else if (ptr->wall_dir[(v.x + v.j) / 4] == 15)
		color = rgb(5, 0, 10);
	ft_setpx((int*)ptr->display.data, v.x + v.j, LENGHT / 2 - v.i,
ft_shader(par.wall_colors[(v.col + 32 * (v.i / (dist / 14)))],
par.dist[v.c]) + color);
	ft_setpx((int*)ptr->display.data, v.x + v.j, LENGHT / 2 + v.i,
ft_shader(par.wall_colors[1023 - (v.col + 32 * (v.i / (dist / 14)))],
par.dist[v.c]) + color);
}

void				put_player(t_param *par, t_param *ptr_par)
{
	t_coor			player;
	t_coor			coor;
	t_var			v;

	v.i = -3;
	player.x = par->pl_x;
	player.y = par->pl_y;
	while (v.i++ != 2)
	{
		v.j = -3;
		while (v.j++ != 2)
		{
			coor.x = par->pl_x + v.j;
			coor.y = par->pl_y + v.i;
			ft_setpx_2((int*)ptr_par->minimap.data, coor, 0xFF00FF,
ptr_par->size_map);
		}
	}
	v.i = 0;
	ptr_par->side = side_check(*ptr_par);
	ray_cast(v, par, ptr_par, player);
	par->ray_n = 1;
}
