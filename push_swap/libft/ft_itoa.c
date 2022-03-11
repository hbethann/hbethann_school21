/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/13 05:03:01 by hbethann          #+#    #+#             */
/*   Updated: 2021/11/13 05:29:43 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_zero(int n, char *str)
{
	if (n == 0)
	{
		str[0] = '0';
		str[1] = '\0';
	}
	return (str);
}

static int	ft_sign(int n)
{
	int	s;

	s = 1;
	if (n < 0)
		s = -1;
	return (s);
}

static int	ft_len(int n)
{
	int	l;

	l = 0;
	if (n <= 0)
		l = 1;
	while (n != 0)
	{
		l++;
		n = n / 10;
	}
	return (l);
}

char	*ft_itoa(int n)
{
	int		l;
	int		s;
	char	*str;

	s = ft_sign(n);
	l = ft_len(n);
	str = (char *)malloc(sizeof(char) * (l + 1));
	if (!str)
		return (str);
	ft_zero(n, str);
	str[l] = '\0';
	while (n != 0)
	{
		str[--l] = (char)((n % 10) * ((2 *(n > 0)) - 1) + 48);
		n = n / 10;
	}
	l--;
	if (s < 0)
		str[l] = '-';
	return (str);
}
