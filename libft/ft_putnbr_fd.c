/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_putnbr_fd.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 10:05:14 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:01:40 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void				ft_putnbr_fd(int n, int fd)
{
	unsigned int	b;

	b = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		b = b * -1;
	}
	if (b > 9)
	{
		ft_putnbr_fd(b / 10, fd);
		ft_putchar_fd(b % 10 + '0', fd);
	}
	if (b <= 9)
		ft_putchar_fd(b + '0', fd);
}
