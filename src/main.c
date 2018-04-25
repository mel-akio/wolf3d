/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 13:39:34 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/25 12:55:32 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

int				cross_close(t_param *param)
{
	exit_game(param);
	return (0);
}

void			ft_hook(t_param *param)
{
	mlx_hook(param->win, 17, 0L, cross_close, param);
	mlx_hook(param->win, KEY_PRESS, KEY_PRESS_MASK, key_event, param);
}

int				main(int argc, char **argv)
{
	int			fd;
	char		**line;
	t_param		param;
	t_coor		size;

	if (usage(argc) || secure(argv[1]) == 0)
		return (0);
	var_init(&param);
	size = map_size(argv[1]);
	if (usage(argc) && size.z == -1)
		return (0);
	fd = open(argv[1], O_RDONLY);
	line = ft_memalloc(sizeof(char*) * (size.y * size.y) + 1);
	while (get_next_line(fd, &line[param.l_y]))
		param.l_y++;
	ft_strdel(&line[param.l_y]);
	param.map = make_map(line, &param, size);
	if (param.map == 0 || (param.l_x > 25 || param.l_y > 25))
		return (0);
	textures_init(&param);
	mlx_put_image_to_window(param.mlx, param.win, param.menu.ptr, 0, 0);
	mlx_key_hook(param.win, key_event, &param);
	ft_hook(&param);
	mlx_loop(param.mlx);
	exit_game(&param);
}
