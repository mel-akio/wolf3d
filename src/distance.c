/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   distance.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/21 15:23:36 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 17:00:02 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

float		distance(float x1, float y1, float x2, float y2)
{
	float	a;
	float	b;

	a = x1 - x2;
	b = y1 - y2;
	return (sqrt(a * a + b * b));
}

void		direction(t_param *par)
{
	int		x;
	int		y;

	x = par->pl_x;
	y = par->pl_y;
	if (par->degres >= M_PI * 2)
		par->degres -= M_PI * 2;
	else if (par->degres < 0)
		(par->degres += M_PI * 2);
	if (par->direction == 1)
	{
		par->degres += (float)par->iter / (360 * FOV);
		par->angle.x = ((VIEW_DISTANCE) * cos(par->degres)) + x;
		par->angle.y = ((VIEW_DISTANCE) * sin(par->degres)) + y;
	}
	else if (par->direction == -1)
	{
		par->degres -= (float)par->iter / (360 * FOV);
		par->angle.x = ((VIEW_DISTANCE) * cos(par->degres)) + x;
		par->angle.y = ((VIEW_DISTANCE) * sin(par->degres)) + y;
	}
}

float		draw_line(t_coor p1, t_coor p2, t_param param, t_param *ptr_par)
{
	int		x;
	int		i;
	int		dist;

	i = 0;
	p2 = param.angle;
	x = p1.x;
	if (p2.x > p1.x - 360 && p2.x < (param.l_y * 10) + (p1.x + 110))
		return (draw_line2(p1, p2, param, ptr_par));
	if (x <= p2.x)
		i = step_x1(p1, p2, &x, ptr_par);
	else if (x > p2.x)
		i = step_x2(p1, p2, &x, ptr_par);
	dist = (distance(p1.x, p1.y, x, p1.y + ((p2.y - p1.y) * (x - p1.x)) /
(p2.x - p1.x)));
	if (param.side == 1)
		return (i);
	return (dist);
}

float		draw_line2(t_coor p1, t_coor p2, t_param param, t_param *ptr_par)
{
	int		y;
	int		i;
	int		dist;

	i = 0;
	y = p1.y;
	if (y <= p2.y)
		i = step_y1(p1, p2, &y, ptr_par);
	else if (y > p2.y)
		i = step_y2(p1, p2, &y, ptr_par);
	dist = distance(p1.x, p1.y, p1.x + ((p2.x - p1.x) * (y - p1.y)) /
(p2.y - p1.y), y);
	if (param.side == 2)
		return (i);
	return (dist);
}

void		rotate(t_param *par, int n)
{
	while (n-- > 0)
	{
		direction(par);
		if (par->mid_dist < 3)
			par->degres += (par->direction * 0.015);
		else if (par->mid_dist < 20)
			par->degres += (par->direction * 0.010);
		else
			par->degres += (par->direction * 0.005);
	}
	par->direction = 0;
}
