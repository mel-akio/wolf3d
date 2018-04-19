/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   display.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/05 16:58:28 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 18:20:19 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void				ft_setpx(int *img, int x, int y, int color)
{
	if (x < 0 || x > WIDTH || y < 0 || y > LENGHT)
		return ;
	img[x + y * WIDTH] = color;
}

void				ft_setpx_2(int *img, t_coor coor, int color, t_size size)
{
	if (!(coor.x < 0 || coor.x > size.width || coor.y < 0 ||
coor.y > size.lenght))
		img[coor.x + coor.y * size.width] = color;
}

void				make_mask(t_param *param, t_img *img, char xpm[255],
t_size size)
{
	img->ptr = mlx_xpm_file_to_image(param->mlx,
xpm, &size.width, &size.lenght);
	img->data = mlx_get_data_addr(img->ptr, &param->i[0], &param->i[1],
	&param->i[2]);
}

void				print_objects(t_param *param)
{
	int				i;

	i = 0;
	while (i < ITER)
	{
		if (param->object[i].sprite_id == 2)
			mlx_put_image_to_window(param->mlx, param->win, param->monster.ptr,
param->object[i].position, (LENGHT / 4) + param->object[i].distance);
		param->object[i].sprite_id = 0;
		i++;
	}
}

unsigned int		ft_shader(int color, unsigned int distance)
{
	unsigned int	shader;

	distance /= 1.25;
	shader = rgb(distance, distance, distance);
	if (color - shader > 0x221100 && color - shader < 0xFFFFFF)
		color -= shader;
	else
		color = 0x090909;
	return (color);
}
