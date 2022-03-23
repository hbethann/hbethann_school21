/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:05:15 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/23 23:47:53 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	stack_add(t_stack *stack, char **arr)
{
	int	*sort_arr;
	int	*not_sort_arr;
	int	num;
	int	len;
	int	i;

	i = -1;
	len = 0;
	while (arr[++i])
		len++;
	sort_arr = malloc(sizeof(int) * len);
	not_sort_arr = malloc(sizeof(int) * len);
	while (i < len)
	{
		num = ft_atoi(arr[i]);
		sort_arr[i] = num;
		not_sort_arr[i] = num;
		i++;
	}
	bubble_sorting(stack, sort_arr, not_sort_arr, len);
}

void	bubble_sorting(t_stack *stack, int *sort_arr,
		int *not_sort_arr, int len)
{
	char	tmp;
	int		i;
	int		j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < (len - 1 - i))
		{
			if (sort_arr[j] > sort_arr[j + 1])
			{
				tmp = sort_arr[j];
				sort_arr[j] = sort_arr[j + 1];
				sort_arr[j + 1] = tmp;
			}
			j++;
		}
		i++;
	}
	create_stack(stack, sort_arr, not_sort_arr, len);
}

void	create_stack(t_stack *stack, int *sort_arr,
		int *not_sort_arr, int len)
{
	int	i;
	int	j;

	i = 0;
	while (i < len)
	{
		j = 0;
		while (j < len)
		{
			if (not_sort_arr[i] == sort_arr[j])
			{
				lstadd_back(&stack->stack_a, new_list(not_sort_arr[i], j + 1));
				j++;
				break ;
			}
			j++;
		}
		i++;
	}
	free(sort_arr);
	free(not_sort_arr);
}
