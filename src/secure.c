/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   secure.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 15:07:48 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/26 14:47:01 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int			secure(char *path)
{
	int		ok;

	ok = 0;
	if (ft_strcmp(path, "maps/map") == 0)
		ok = 1;
	else if (ft_strcmp(path, "maps/map2") == 0)
		ok = 1;
	else if (ft_strcmp(path, "maps/map3") == 0)
		ok = 1;
	if (!ok)
		ft_putstr("Usage : ./wolf3d maps/<filename>\n");
	return (ok);
}

t_coor		*close_map(t_coor *map, t_param *param)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	x = 0;
	i = 0;
	while (y != param->l_y)
	{
		while (x != param->l_x)
		{
			if (y == 0 || x == 0 || y == param->l_y - 1 || x == param->l_x - 1)
				map[i].z = 1;
			x++;
			i++;
		}
		x = 0;
		y++;
	}
	map[param->l_x + 1].z = 0;
	return (map);
}
