/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_mlx2.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 17:00:26 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/24 15:59:53 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				ray_cast(t_var v, t_param *par, t_param *ptr_par,
t_coor player)
{
	while (v.i != par->iter)
	{
		par->ray_n++;
		par->direction = 1;
		direction(par);
		par->dist[v.i] = draw_line(player, player, *par, ptr_par);
		par->angles[v.i].degres = par->degres;
		v.i++;
	}
}

unsigned int		rgb(unsigned char r, unsigned char g, unsigned char b)
{
	if (r > 255)
		r = 255;
	if (r > 255)
		g = 255;
	if (r > 255)
		b = 255;
	return ((r * 65536) + (g * 256) + b);
}

void				make_ground(t_img *img)
{
	int				i;
	int				j;
	float			c;

	i = LENGHT / 2;
	j = 0;
	c = 2;
	while (i < LENGHT)
	{
		while (j < WIDTH)
		{
			ft_setpx((int*)img->data, j, i, rgb(c, c + 15, c));
			j++;
		}
		j = 0;
		c += 0.14;
		i++;
	}
}

void				skybox(t_param *param, int x, int y)
{
	mlx_put_image_to_window(param->mlx, param->win, param->background.ptr,
(x + WIDTH - (param->degres) * 128), y);
	mlx_put_image_to_window(param->mlx, param->win, param->background.ptr,
(x - (param->degres) * 128), y);
}

void				texture_in_tab(t_param *param)
{
	int				i;
	int				j;

	j = 0;
	i = 0;
	while (param->wall.data[i])
	{
		param->wall_colors[j] = rgb(param->wall.data[i + 2], param->
wall.data[i + 1], param->wall.data[i]);
		i += 4;
		j++;
	}
}
