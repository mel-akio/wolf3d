/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 11:09:57 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2018/01/14 14:05:34 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	len_s1;
	size_t	len_s2;

	i = 0;
	j = 0;
	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	if (!(str = ft_memalloc(len_s1 + len_s2 + 1)))
		return (NULL);
	if (str == NULL || s1 == NULL || s2 == NULL)
		return (NULL);
	while (i < len_s1)
	{
		str[i] = s1[i];
		i++;
	}
	while (j < len_s2)
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}
