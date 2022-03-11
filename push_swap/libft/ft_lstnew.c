/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 16:05:12 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/10 16:55:26 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mem_space;

	mem_space = malloc(sizeof(t_list) * 1);
	if (mem_space == NULL)
		return (NULL);
	mem_space -> content = content;
	mem_space -> next = NULL;
	return (mem_space);
}
