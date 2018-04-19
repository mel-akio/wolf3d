/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/09 11:40:13 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:01:47 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int n)
{
	long	b;

	b = n;
	if (n < 0)
	{
		ft_putchar('-');
		b = b * -1;
	}
	if (b > 9)
	{
		ft_putnbr(b / 10);
		ft_putchar(b % 10 + '0');
	}
	if (b <= 9)
		ft_putchar(b + '0');
}