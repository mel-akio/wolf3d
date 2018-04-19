/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/18 19:59:16 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 14:27:19 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static size_t		s_nl(char *str)
{
	size_t			i;

	i = 0;
	if (str[0] == '\n')
		return (1);
	while (str[i] != '\n' && str[i] != '\0')
		i++;
	return (i + 1);
}

static int			process(char **temp, char end[BUFF_SIZE + 1], int fd)
{
	int				size;

	while (!(ft_strchr(temp[fd], '\n')))
	{
		size = read(fd, end, BUFF_SIZE);
		if (size == -1)
			return (-1);
		if (size != BUFF_SIZE)
		{
			end[size] = '\0';
			temp[fd] = ft_strjoin_free(temp[fd], ft_strdup(end));
			break ;
		}
		temp[fd] = ft_strjoin_free(temp[fd], ft_strdup(end));
	}
	return (size);
}

int					get_next_line(const int fd, char **line)
{
	static char		*temp[8192];
	char			end[BUFF_SIZE + 1];
	int				size;

	ft_bzero(end, BUFF_SIZE + 1);
	if (fd < 0 || fd > 8192)
		return (-1);
	if (!temp[fd])
		if (!(temp[fd] = ft_strnew(BUFF_SIZE)))
			return (0);
	size = process(temp, end, fd);
	if (size == -1)
		return (size);
	*line = ft_strsub(temp[fd], 0, s_nl(temp[fd]));
	temp[fd] = ft_strsub_free(temp[fd], s_nl(temp[fd]), ft_strlen(temp[fd]));
	if (*line[0])
		size = 1;
	else
		size = 0;
	if ((*line)[ft_strlen(*line) - 1] == '\n')
		(*line)[ft_strlen(*line) - 1] = '\0';
	return (size);
}
