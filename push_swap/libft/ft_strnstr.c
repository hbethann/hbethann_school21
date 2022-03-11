/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:07:43 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/10 19:16:02 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;

	i = ft_strlen(needle);
	if (!(*needle))
		return ((char *)haystack);
	while (*haystack && i <= len)
	{
		if (ft_strncmp(haystack, needle, i) == 0)
			return ((char *)haystack);
		haystack++;
		len--;
	}
	return (NULL);
}
