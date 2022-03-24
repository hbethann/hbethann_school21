/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 19:59:25 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/24 20:52:10 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str && str[i] && (str[i] == ' ' || str[i] == '\v' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\t' || str[i] == '\f'))
		i++;
	if (str && str[i] && (str[i] == '-' || str[i] == '+'))
	{
		if (str[i++] == '-')
			sign = -1;
	}
	while (str && str[i] && ft_isdigit(str[i]))
	{
		res *= 10;
		res += str[i++] - '0';
	}
	return (res * sign);
}
