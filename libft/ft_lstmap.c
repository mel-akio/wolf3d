/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_lstmap.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: mel-akio <mel-akio@student.le-101.fr>      +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/21 13:39:48 by mel-akio     #+#   ##    ##    #+#       */
/*   Updated: 2017/12/20 14:00:04 by mel-akio    ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!(new = ft_memalloc(sizeof(new))) || !lst)
		return (NULL);
	new = f(lst);
	if (lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
