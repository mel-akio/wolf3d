/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strtrim.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 13:14:36 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:06:43 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s)
{
	char	*str;
	int		i;
	size_t	start;
	size_t	end;

	start = 0;
	end = 0;
	i = -1;
	if (s == NULL)
		return (NULL);
	while (s[++i] && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		start++;
	i = ft_strlen(s);
	while (--i != 0 && (s[i] == '\t' || s[i] == '\n' || s[i] == ' '))
		end++;
	if (start >= ft_strlen(s) - 1)
		str = ft_strdup("");
	else
		str = ft_strsub(s, start, ft_strlen(s) - ((end + start)));
	return (str);
}
