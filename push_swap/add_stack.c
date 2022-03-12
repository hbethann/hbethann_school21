/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 22:05:15 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/12 20:04:35 by hbethann         ###   ########.fr       */
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
