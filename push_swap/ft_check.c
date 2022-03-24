/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 07:28:35 by drgnvgr           #+#    #+#             */
/*   Updated: 2022/03/24 21:01:39 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_SUCCESS);
}

void	free_array(char **array, int flag)
{
	int	i;

	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
	if (flag)
		error();
}

void	check_arg(char **array)
{
	int			i;
	int			j;
	long long	num;

	i = -1;
	while (array[++i])
	{
		j = 0;
		while (array[i][j])
		{
			if (array[i][j] == '-')
				j++;
			if (!(ft_isdigit(array[i][j])))
				free_array(array, 1);
			j++;
		}
	}
	num = ft_atoi(array[i]);
	if (num > MAX_INT || num < MIN_INT)
		free_array(array, 1);
}

char	**ft_line(char **argv)
{
	int		i;
	char	*line;
	char	**array;
	char	*tmp;

	line = ft_strdup(argv[1]);
	i = 1;
	while (argv[++i])
	{
		tmp = line;
		line = ft_strjoin(line, " ");
		free(tmp);
		tmp = line;
		line = ft_strjoin(line, argv[i]);
		free(tmp);
	}
	array = ft_split(line, ' ');
	free(line);
	return (array);
}

void	twins(char **array)
{
	int	i;
	int	j;

	i = 0;
	while (array[i])
	{
		j = i + 1;
		while (array[j])
		{
			if (ft_atoi(array[i]) == ft_atoi(array[j]))
				free_array(array, 1);
			j++;
		}
		i++;
	}
}
