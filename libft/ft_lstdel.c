/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstdel.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/21 11:43:17 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 13:59:40 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*swp;

	while ((*alst))
	{
		swp = (*alst)->next;
		(*del)((*alst)->content, (*alst)->content_size);
		ft_memdel((void*)alst);
		(*alst) = swp;
	}
	alst = NULL;
}
