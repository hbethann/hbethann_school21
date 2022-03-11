/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 19:07:50 by hbethann          #+#    #+#             */
/*   Updated: 2021/11/16 00:48:15 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s1;
	int		i;

	i = 0;
	s1 = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			s1 = (char *)(s + i);
		i++;
	}
	if (s[i] == (char)c)
		s1 = (char *)(s + i);
	return (s1);
}
