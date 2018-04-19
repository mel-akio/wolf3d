/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memcpy.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/18 14:39:13 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:00:43 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*str;
	char	*str2;

	str = (char *)src;
	str2 = (char *)dest;
	i = 0;
	while (i < n)
	{
		str2[i] = str[i];
		i++;
	}
	return (dest);
}
