/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strchr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/15 20:49:16 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:02:32 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	ch;

	ch = c;
	i = 0;
	while (s[i] && (s[i] != ch))
		i++;
	if (s[i] == ch)
		return ((char*)&s[i]);
	return (NULL);
}
