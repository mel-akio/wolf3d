/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strndup.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 11:09:35 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/04/18 12:48:28 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strndup(const char *s, size_t n)
{
	char	*str;

	if (!(str = ft_memalloc(n + 1)))
		return (NULL);
	ft_strncpy(str, s, n);
	return (str);
}
