/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drgnvgr <drgnvgr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:09:02 by drgnvgr           #+#    #+#             */
/*   Updated: 2022/03/16 11:22:29 by drgnvgr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_med_max_a(t_stack *stack)
{
	int	min;
	int	max;
	int	i;

	if (stack->size_a == 0)
		return ;
	i = stack->size_a;
	min = stack->stack_a->index;
	max = stack->stack_a->index;
	while (i-- > 0)
	{
		if (min > stack->stack_a->index)
			min = stack->stack_a->index;
		if (max < stack->stack_a->index)
			max = stack->stack_a->index;
		stack->stack_a = stack->stack_a->next;
	}
	stack->min = min;
	stack->max = max;
	stack->med = (min + max) / 2;
}
