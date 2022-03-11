/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 16:38:52 by hbethann          #+#    #+#             */
/*   Updated: 2021/11/15 23:13:37 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t len)
{
	size_t	dest_l;
	size_t	src_l;

	if (!dst && !src)
		return (0);
	dest_l = ft_strlen(dst);
	src_l = ft_strlen(src);
	if (len < dest_l)
		return (len + src_l);
	else
	{
		dst += dest_l;
		ft_strlcpy(dst, src, (len - dest_l));
		return (dest_l + src_l);
	}
}
