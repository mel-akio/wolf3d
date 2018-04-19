/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsub_free.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/10 16:25:48 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:06:26 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub_free(char const *s, unsigned int start, size_t len)
{
	char	*str;

	if (s != NULL)
	{
		str = ft_strndup(&s[start], len);
		ft_strdel((char**)&s);
		return (str);
	}
	return (NULL);
}
