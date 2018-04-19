/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strrchr.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/20 13:35:10 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:06:05 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = c;
	i = ft_strlen(s);
	while (i != 0 && (s[i] != ch))
		i--;
	if (s[i] == ch)
		return ((char*)&s[i]);
	return (NULL);
}
