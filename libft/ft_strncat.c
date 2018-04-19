/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strncat.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/18 19:18:31 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:04:43 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strncat(char *dest, const char *src, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (dest[i])
		i++;
	while (src[j] && n-- > 0)
		dest[i++] = src[j++];
	dest[i] = '\0';
	return (dest);
}
