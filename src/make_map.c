/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   make_map.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/14 13:39:22 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/20 15:48:57 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "../includes/wolf3d.h"

t_coor		*convert_int(char ***str, t_param param)
{
	t_coor	*map;
	t_coor	count;

	count.x = 0;
	count.y = 0;
	count.z = 0;
	if (!(map = (t_coor *)malloc((sizeof(int) * 4) * (param.l_x * param.l_y))))
		exit(0);
	while (count.x < param.l_y)
	{
		while (count.y < param.l_x)
		{
			map[(int)count.z].z = ft_atoi(str[(int)count.x][(int)count.y]);
			map[(int)count.z].x = count.y;
			map[(int)count.z].y = count.x;
			ft_strdel(&str[(int)count.x][(int)count.y]);
			count.y++;
			count.z++;
		}
		free(str[(int)count.x++]);
		count.y = 0;
	}
	free(str);
	map[(int)count.z].z = -100000;
	return (close_map(map, &param));
}

t_coor		*make_map(char **str, t_param *param, t_coor size)
{
	int		i;
	char	***map;

	i = 0;
	if (!(map = ft_memalloc(sizeof(char **) * size.y + 1)))
		exit(0);
	while (str[i] != NULL)
	{
		map[i] = ft_strsplit(str[i], ' ');
		free(str[i]);
		i++;
	}
	free(str[i]);
	free(str);
	map[i] = NULL;
	i = 0;
	while (map[0][param->l_x] != NULL)
		param->l_x++;
	if (check_map(map))
		return (0);
	return (convert_int(map, *param));
}

t_coor		map_size(char *name)
{
	t_coor	size;
	size_t	len;
	int		fd;
	char	*line;

	len = 0;
	fd = open(name, O_RDONLY);
	if (fd == -1)
	{
		size.z = -1;
		close(fd);
		return (size);
	}
	while (get_next_line(fd, &line))
	{
		ft_strdel(&line);
		size.y++;
	}
	close(fd);
	free(line);
	return (size);
}

int			check_map(char ***map)
{
	t_coor	i;
	int		len;

	i.y = -1;
	while (map[(int)++i.y])
	{
		while (map[(int)i.y][(int)i.z])
		{
			if (!(ft_isdigit(map[(int)i.y][(int)i.z][0])) &&
	map[(int)i.y][(int)i.z][0] != '-')
				return (1);
			i.z++;
		}
		if (i.y != 0 && len != i.z)
			return (1);
		len = i.z;
		i.z = 0;
	}
	return (0);
}

int			usage(int argc)
{
	if (argc != 2)
	{
		ft_putstr("Usage : ./wolf3d maps/<filename>\n");
		return (1);
	}
	return (0);
}
