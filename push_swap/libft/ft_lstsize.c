/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:59:18 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/10 18:05:35 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*iter;
	int		i;

	i = 0;
	iter = lst;
	while (iter != NULL)
	{
		iter = iter -> next;
		i++;
	}
	return (i);
}
