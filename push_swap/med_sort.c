/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   med_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drgnvgr <drgnvgr@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 13:09:02 by drgnvgr           #+#    #+#             */
/*   Updated: 2022/03/22 18:16:25 by drgnvgr          ###   ########.fr       */
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

void	min_med_max_b(t_stack *stack)
{
	int		i;
	int		min;
	int		max;

	if (stack->size_b == 0)
		return ;
	i = stack->size_b;
	min = stack->stack_b->index;
	max = stack->stack_b->index;
	while (i-- > 0)
	{
		if (min > stack->stack_b->index)
			min = stack->stack_b->index;
		if (max < stack->stack_b->index)
			max = stack->stack_b->index;
		stack->stack_b = stack->stack_b->next;
	}
	stack->max = max;
	stack->med = (min + max) / 2;
}

void	move_down(t_stack *stack)
{
	while (stack->stack_b->prev->flags == -1)
		rrb(stack, 1);
	while (stack->stack_b->flags == -1)
	{
		pa(stack, 1);
		ra(stack, 1);
	}
}

void	move_a_to_b_first(t_stack *stack)
{
	int	i;

	min_med_max_a(stack);
	i = stack->size_a;
	while (i-- > 0)
	{
		if (stack->stack_a->index <= stack->med)
		{
			pb(stack, 1);
			if (stack->stack_b->index == stack->min)
			{
				stack->stack_b->flags = -1;
				rb(stack, 1);
			}
		}
		else
		{
			if (stack->size_b == stack->max - stack->med + 1)
				break ;
			else
				ra (stack, 1);
		}
	}
	move_down(stack);
}
