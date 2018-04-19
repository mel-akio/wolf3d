/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   secure.c                                         .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/19 15:07:48 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 18:20:59 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int		secure(char *path)
{
	int	ok;

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
