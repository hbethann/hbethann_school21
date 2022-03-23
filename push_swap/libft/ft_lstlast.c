/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 18:05:57 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/23 23:43:08 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*iter;

	iter = lst;
	if (lst == NULL)
		return (NULL);
	while (iter -> next != NULL)
		iter = iter -> next;
	return (iter);
}
