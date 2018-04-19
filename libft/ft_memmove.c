/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_memmove.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/16 19:26:37 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:00:56 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*dst;
	char	*sr;

	sr = (char *)src;
	dst = (char *)dest;
	i = 0;
	if (src < dest)
		while (n--)
			dst[n] = sr[n];
	else
		ft_memcpy(dst, sr, n);
	return (dst);
}
