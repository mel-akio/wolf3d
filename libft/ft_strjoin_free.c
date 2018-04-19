/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strjoin_free.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 11:09:57 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:03:57 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin_free(char const *s1, char const *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free((char*)s1);
	free((char*)s2);
	return (str);
}
