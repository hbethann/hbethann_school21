/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int2char.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 15:02:35 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/29 18:25:59 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*mem_str(int size)
{
	void	*heap;

	heap = NULL;
	while (!heap)
		heap = malloc(size);
	return (heap);
}

static int	size_int(int num)
{
	int	size;

	size = 0;
	size++;
	if (num < 0)
		size++;
	while (1)
	{
		if (num < 0)
		{
			if (num >= -9)
				break ;
		}
		else
		{
			if (num <= 9)
				break ;
		}
		size++;
		num /= 10;
	}
	return (size);
}

static char	*int2char(int n, int size, char *str)
{
	int	mod;
	int	buf;
	int	sing;

	sing = 0;
	str[size] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		sing = 1;
	}
	buf = n;
	while (size - sing)
	{
		mod = buf % 10;
		if (mod < 0)
			mod *= -1;
		str[size - 1] = mod + '0';
		buf /= 10;
		size--;
	}
	return (str);
}

char	*mem_i2c(int num)
{
	int			size;
	char		*str;

	size = size_int(num);
	str = mem_str(size + 1);
	return (int2char(num, size, str));
}
