/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   init.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/04/04 14:02:37 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/19 18:20:32 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

void			var_init(t_param *param)
{
	param->display.ptr = malloc(1024 * 1024);
	param->wall_colors = malloc(sizeof(int) * (32 * 32) + 1);
	param->object = malloc(sizeof(param->object) * ITER + 1);
	param->angles = malloc(sizeof(t_angle) * 500);
	param->angle.y = 0;
	param->angle.x = 30;
	param->iter = ITER;
	param->pl_x = 12;
	param->pl_y = 12;
	param->degres = 0;
	param->width = 800;
	param->height = 600;
	param->textures_size.width = 32;
	param->textures_size.lenght = 32;
	param->hide_map = 1;
}

void			textures_init(t_param *param)
{
	t_size skybox;
	t_size wall;
	t_size gun;
	t_size crosshair;

	skybox.width = 800;
	skybox.lenght = 600;
	wall.width = 32;
	wall.lenght = 32;
	gun.width = 390;
	gun.lenght = 260;
	crosshair.width = 285;
	crosshair.lenght = 365;
	param->mlx = mlx_init();
	param->win = mlx_new_window(param->mlx, WIDTH, LENGHT, "Wolf3D");
	param->size_map.width = param->l_x * BLOCK_SIZE;
	param->size_map.lenght = param->l_y * BLOCK_SIZE;
	make_mask(param, &param->background, "backgrounds/skybox2.xpm", skybox);
	make_mask(param, &param->menu, "backgrounds/menu.xpm", skybox);
	make_mask(param, &param->post_traitment, "backgrounds/mask.xpm", skybox);
	make_ground(&param->background);
	make_mask(param, &param->wall, "backgrounds/wall.xpm", wall);
	make_mask(param, &param->gun, "backgrounds/gun2.xpm", gun);
	make_mask(param, &param->crosshair, "backgrounds/crosshair.xpm", crosshair);
	texture_in_tab(param);
}

void			refresh_screen(t_param *param)
{
	skybox(param, 0, 0);
	put_map(*param, 0, param);
	mlx_put_image_to_window(param->mlx, param->win, param->gun.ptr, (WIDTH /
2.5) + 70 - (int)param->motion % 12, (LENGHT / 2) + (int)param->motion % 12);
	mlx_put_image_to_window(param->mlx, param->win, param->crosshair.ptr,
(WIDTH / 2) - 16, (LENGHT / 2) - 16);
	mlx_put_image_to_window(param->mlx, param->win, param->post_traitment.ptr,
0, 0);
	param->ray_n = 0;
}

void			texture_position(unsigned int x, unsigned int y, t_param *param)
{
	if (x % 10 == 0 || x - 9 % 10 == 0)
		param->angles[param->ray_n].texture_col = y % 32;
	else if (y % 10 == 0 || y - 9 % 10 == 0)
		param->angles[param->ray_n].texture_col = x % 32;
	param->ray_n++;
}

void			exit_game(t_param *param)
{
	free(param->angles);
	free(param->display.ptr);
	free(param->wall_colors);
	free(param->object);
	free(param->map);
	mlx_destroy_image(param->mlx, param->background.ptr);
	mlx_destroy_image(param->mlx, param->wall.ptr);
	mlx_destroy_image(param->mlx, param->gun.ptr);
	mlx_destroy_image(param->mlx, param->crosshair.ptr);
	mlx_destroy_window(param->mlx, param->win);
	exit(1);
}
