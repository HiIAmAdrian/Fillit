/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adstan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 17:25:45 by adstan            #+#    #+#             */
/*   Updated: 2017/12/12 16:09:57 by adstan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ls;
	t_list *ff;

	if (!lst)
		return (NULL);
	if (!(ls = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	ff = ls;
	lst = lst->next;
	while (lst)
	{
		if ((ls->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		{
			lst = lst->next;
			ls = ls->next;
		}
		else
			return (NULL);
	}
	return (ff);
}
