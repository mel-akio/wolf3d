/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   collision.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/27 15:06:40 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 18:20:16 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		key_event(int keycode, t_param *param)
{
	int	i;

	i = 0;
	if (keycode == KEY_MORE)
		param->hide_map = 1;
	if (keycode == KEY_LESS)
		param->hide_map = 0;
	if (keycode == KEY_LEFT || keycode == KEY_RIGHT)
	{
		param->direction = -1;
		if (keycode == KEY_RIGHT)
			param->direction = 1;
		rotate(param, 10);
	}
	else if (keycode == KEY_ESC)
		exit_game(param);
	else if (keycode == KEY_A || keycode == KEY_W || keycode == KEY_D ||
keycode == KEY_S)
	{
		collision(param, keycode);
		param->motion += 0.3;
	}
	refresh_screen(param);
	return (0);
}

void	collision(t_param *param, int keycode)
{
	if (keycode == KEY_A && ((check_grid(param->pl_x + cos(param->angles[param->
iter / 2].degres - 1.6) * 3, param->pl_y + sin(param->angles[param->iter / 2].
degres - 1.6) * 3, param)) != 1))
	{
		param->pl_x += cos(param->angles[param->iter / 2].degres - 1.6) * 3;
		param->pl_y += sin(param->angles[param->iter / 2].degres - 1.6) * 3;
	}
	else if (keycode == KEY_W && ((check_grid(param->pl_x + cos(param->angles
[param->iter / 2].degres) * 3, param->pl_y + sin(param->angles[param->iter / 2]
.degres) * 3, param)) != 1))
	{
		param->pl_x += cos(param->angles[param->iter / 2].degres) * 3;
		param->pl_y += sin(param->angles[param->iter / 2].degres) * 3;
	}
	collision2(param, keycode);
}

void	collision2(t_param *param, int keycode)
{
	if (keycode == KEY_D && ((check_grid(param->pl_x + cos(param->angles
[param->iter / 2].degres + 1.6) * 3, param->pl_y + sin(param->angles[param->
iter / 2].degres + 1.6) * 3, param)) != 1))
	{
		param->pl_x += cos(param->angles[param->iter / 2].degres + 1.6) * 3;
		param->pl_y += sin(param->angles[param->iter / 2].degres + 1.6) * 3;
	}
	else if (keycode == KEY_S && ((check_grid(param->pl_x - cos(param->angles
[param->iter / 2].degres) * 3, param->pl_y - sin(param->angles[param->iter / 2]
.degres) * 3, param)) != 1))
	{
		param->pl_x -= cos(param->angles[param->iter / 2].degres) * 3;
		param->pl_y -= sin(param->angles[param->iter / 2].degres) * 3;
	}
	direction(param);
}

int		check_grid(unsigned int x, unsigned int y, t_param *par)
{
	int	val;

	val = par->map[(x / BLOCK_SIZE) + (y / BLOCK_SIZE * par->l_x)].z;
	if (val == 2)
	{
		par->object[par->ray_n].sprite_id = 2;
		par->object[par->ray_n].position = (par->ray_n + 1) * 4;
		par->object[par->ray_n].distance = distance(par->pl_x, par->pl_y, x, y);
	}
	return (val);
}

char	side_check(t_param par)
{
	if ((par.angles[par.iter / 2].degres >= M_PI - 0.15 &&
par.angles[par.iter / 2].degres < M_PI + 0.15) ||
(par.angles[par.iter / 2].degres >= 0 - 0.15 &&
par.angles[par.iter / 2].degres < 0 + 0.15))
		return (1);
	if ((par.angles[par.iter / 2].degres >= M_PI_2 - 0.15 &&
par.angles[par.iter / 2].degres < M_PI_2 + 0.15) ||
(par.angles[par.iter / 2].degres >= (M_PI + M_PI / 2) - 0.15 &&
par.angles[par.iter / 2].degres < (M_PI + M_PI / 2) + 0.15))
		return (2);
	return (0);
}
