/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_ignoreblank.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 13:37:52 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 13:58:29 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_ignoreblank(char const *s)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	if (s == NULL)
		return (0);
	while (s[i])
	{
		if (s[i] != 32 && s[i] != '\n' && s[i] != '\t')
			j++;
		i++;
	}
	return (j);
}
