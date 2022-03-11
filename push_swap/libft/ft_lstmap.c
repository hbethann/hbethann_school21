/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:05:02 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/10 19:10:26 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*mem;
	t_list	*tmp;

	tmp = NULL;
	while (lst)
	{
		mem = ft_lstnew((*f)(lst->content));
		if (mem == NULL)
		{
			ft_lstclear(&tmp, mem);
			return (NULL);
		}
		ft_lstadd_back(&tmp, mem);
		lst = lst->next;
	}
	return (tmp);
}
