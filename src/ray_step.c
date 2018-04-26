/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ray_step.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 11:38:35 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 14:18:30 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				step_x1(t_coor p1, t_coor p2, int *x, t_param *ptr_par)
{
	int			i;
	t_coor		coor;

	i = 0;
	while (*x <= p2.x)
	{
		if (check_grid(*x, p1.y + ((p2.y - p1.y) * (*x - p1.x)) /
(p2.x - p1.x), ptr_par) == 1)
		{
			texture_position(*x, p1.y + ((p2.y - p1.y) * (*x - p1.x)) / (p2.x
	- p1.x), ptr_par);
			side_wall(ptr_par, *x % 10, (p1.y + ((p2.y - p1.y) * (*x - p1.x))
	/ (p2.x - p1.x)) % 10);
			break ;
		}
		coor.x = *x;
		coor.y = p1.y + ((p2.y - p1.y) * (*x - p1.x)) / (p2.x - p1.x);
		ft_setpx_2((int*)ptr_par->minimap.data, coor, rgb(0, 0, 255),
ptr_par->size_map);
		*x += 1;
		i++;
	}
	return (i);
}

int				step_x2(t_coor p1, t_coor p2, int *x, t_param *ptr_par)
{
	int			i;
	t_coor		coor;

	i = 0;
	while (*x > p2.x)
	{
		if (check_grid(*x, p1.y + ((p2.y - p1.y) * (*x - p1.x)) / (p2.x -
p1.x), ptr_par) == 1)
		{
			texture_position(*x - 9, p1.y + ((p2.y - p1.y) * (*x - p1.x)) /
(p2.x - p1.x), ptr_par);
			side_wall(ptr_par, *x % 10, (p1.y + ((p2.y - p1.y) * (*x - p1.x))
	/ (p2.x - p1.x)) % 10);
			break ;
		}
		coor.x = *x;
		coor.y = p1.y + ((p2.y - p1.y) * (*x - p1.x)) / (p2.x - p1.x);
		ft_setpx_2((int*)ptr_par->minimap.data, coor, rgb(0, 0, 255),
ptr_par->size_map);
		*x -= 1;
		i++;
	}
	return (i);
}

int				step_y1(t_coor p1, t_coor p2, int *y, t_param *ptr_par)
{
	int			i;
	t_coor		coor;

	i = 0;
	while (*y <= p2.y)
	{
		if (check_grid(p1.x + ((p2.x - p1.x) * (*y - p1.y)) / (p2.y -
p1.y), *y, ptr_par) == 1)
		{
			texture_position(p1.x + ((p2.x - p1.x) * (*y - p1.y)) / (p2.
y - p1.y), *y, ptr_par);
			side_wall(ptr_par, (p1.x + ((p2.x - p1.x) * (*y - p1.y)) / (p2.
y - p1.y)) % 10, *y % 10);
			break ;
		}
		coor.x = p1.x + ((p2.x - p1.x) * (*y - p1.y)) / (p2.y - p1.y);
		coor.y = *y;
		ft_setpx_2((int*)ptr_par->minimap.data, coor, rgb(255, 0, 0),
ptr_par->size_map);
		*y += 1;
		i++;
	}
	return (i);
}

int				step_y2(t_coor p1, t_coor p2, int *y, t_param *ptr_par)
{
	int			i;
	t_coor		coor;

	i = 0;
	while (*y > p2.y)
	{
		if (check_grid(p1.x + ((p2.x - p1.x) * (*y - p1.y)) / (p2.y - p1.y),
*y, ptr_par) == 1)
		{
			texture_position(p1.x + ((p2.x - p1.x) * (*y - p1.y)) / (p2.y -
p1.y), *y - 9, ptr_par);
			side_wall(ptr_par, (p1.x + ((p2.x - p1.x) * (*y - p1.y)) / (p2.
y - p1.y)) % 10, *y % 10);
			break ;
		}
		coor.x = p1.x + ((p2.x - p1.x) * (*y - p1.y)) / (p2.y - p1.y);
		coor.y = *y;
		ft_setpx_2((int*)ptr_par->minimap.data, coor, rgb(255, 0, 0),
ptr_par->size_map);
		*y -= 1;
		i++;
	}
	return (i);
}

int				side_wall(t_param *param, int x, int y)
{
	static int	i = 0;

	if (i >= ITER)
		i = 0;
	param->height = param->height;
	if (x == 0 && y != 9 && y != 0)
		param->wall_dir[i] = 5;
	else if (x == 9 && y != 9 && y != 0)
		param->wall_dir[i] = 10;
	else if (y == 0 && x != 9 && x != 0)
		param->wall_dir[i] = 15;
	else if (y == 9 && x != 9 && x != 0)
		param->wall_dir[i] = 20;
	else
		param->wall_dir[i] = 0;
	i++;
	//if (i == 200)
		//color_fix(param);
	return (0);
}
