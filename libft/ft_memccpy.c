/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memccpy.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/18 14:23:52 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:00:23 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	str = (char *)src;
	str2 = (char *)dst;
	i = 0;
	while (i < n)
	{
		str2[i] = str[i];
		if ((unsigned char)str[i] == (unsigned char)c)
			return (&str2[i + 1]);
		i++;
	}
	return (NULL);
}
