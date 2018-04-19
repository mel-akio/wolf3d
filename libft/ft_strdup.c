/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strdup.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 11:09:53 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:03:06 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *s)
{
	char	*str;

	if (!(str = malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	ft_strcpy(str, s);
	return (str);
}
