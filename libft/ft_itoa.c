/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_itoa.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/13 18:35:28 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 13:59:26 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

static long		len_alloc(long n)
{
	int			i;

	i = 2;
	if (n < 0)
		i++;
	while (n > 9)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static long		left(long n)
{
	size_t		i;

	i = 1;
	while (n > 9)
	{
		n /= 10;
		i *= 10;
	}
	return (i);
}

static int		count_zero(long n)
{
	size_t		i;

	i = 0;
	while (n > 0)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static char		*cut_number(char *str, long n2, int decal, size_t i)
{
	int			zero;

	zero = 0;
	while (n2 > 0)
	{
		str[i++] = (n2 / decal) + '0';
		n2 -= decal * (n2 / decal);
		zero = count_zero(decal) - 1;
		decal /= 10;
		if (n2 <= 0)
			while (zero--)
				str[i++] = '0';
	}
	return (str);
}

char			*ft_itoa(int n)
{
	int			decal;
	long		n2;
	char		*str;
	size_t		i;

	i = 0;
	if (!(str = ft_memalloc(len_alloc(n))))
		return (NULL);
	if (n == 0)
		return (ft_strdup("0"));
	n2 = n;
	if (n2 < 0)
	{
		n2 *= -1;
		str[i++] = '-';
	}
	decal = left(n2);
	str = cut_number(str, n2, decal, i);
	return (str);
}
