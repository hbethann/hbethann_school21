/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 21:36:41 by hbethann          #+#    #+#             */
/*   Updated: 2021/11/15 22:16:48 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*mmr;

	if ((size * size > ((size_t) - 1) && (size_t) - 1 / count < size)
		|| count * count > ((size_t) - 1))
		return (NULL);
	mmr = malloc(size * count);
	if (!mmr)
		return (NULL);
	ft_memset(mmr, 0, (size * count));
	return (mmr);
}
