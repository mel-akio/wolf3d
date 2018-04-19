/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strsplit.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/20 10:30:59 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:06:11 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	int		k;
	int		l;
	char	**str;

	i = 0;
	k = 0;
	if (!(str = ft_memalloc(sizeof(char *) * (ft_count_word(s, c) + 1))) || !s)
		return (NULL);
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		l = i;
		j = 0;
		while (s[i] != c && s[i])
		{
			i++;
			j++;
		}
		if (j)
			str[k++] = ft_strndup(s + l, j);
	}
	return (str);
}
