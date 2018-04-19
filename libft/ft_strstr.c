/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strstr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/18 15:59:22 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:06:18 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	size_t	i;
	size_t	l;
	char	*nee;
	char	*hay;

	nee = (char*)needle;
	hay = (char*)haystack;
	l = ft_strlen(needle);
	i = 0;
	if (!l)
		return ((char*)haystack);
	while (hay[i])
	{
		if (ft_strncmp(&hay[i], nee, l) == 0)
			return (&hay[i]);
		i++;
	}
	return (NULL);
}
