/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egor <egor@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 18:19:53 by drgnvgr           #+#    #+#             */
/*   Updated: 2022/03/27 18:12:52 by egor             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_down(t_stack *stack)
{
	stack->stack_a->flags = -1;
	ra(stack, 1);
}

int	search_min_b_to_a(t_stack *stack)
{
	int	min;

	min = stack->stack_a->prev->index + 1;
	if (stack->stack_b->index == min)
	{
		pa(stack, 1);
		push_down(stack);
		return (1);
	}
	else if (stack->stack_a->index == min)
		push_down(stack);
	else if (stack->stack_a->next->index == min)
	{
		sa(stack, 1);
		push_down(stack);
	}
	return (0);
}

void	move_b_to_a(t_stack *stack)
{
	int	i;

	min_med_max_b(stack);
	i = stack->size_b;
	while (i-- > 0)
	{
		if (search_min_b_to_a(stack))
			continue ;
		if (stack->stack_b->index > stack->med)
		{
			stack->stack_b->flags++;
			pa(stack, 1);
		}
		else
		{
			stack->stack_b->flags++;
			rb(stack, 1);
		}
	}
}

void	search_min_a_to_b(t_stack *stack)
{
	int	min;

	min = stack->stack_a->prev->index + 1;
	if (stack->stack_b->index == min)
	{
		pa(stack, 1);
		push_down(stack);
	}
	else if (stack->stack_b->next->index == min)
	{
		sb(stack, 1);
		pa(stack, 1);
		push_down(stack);
	}
	else if (stack->stack_b->prev->index == min)
	{
		rrb(stack, 1);
		pa(stack, 1);
		push_down(stack);
	}
	else if (stack->stack_a->next->index == min)
	{
		sa(stack, 1);
		push_down(stack);
	}
}

void	move_a_to_b(t_stack *stack)
{
	int	flags;
	int	min;

	flags = stack->stack_a->flags;
	while (stack->stack_a->flags == flags && flags != -1)
	{
		min = stack->stack_a->prev->index + 1;
		if (stack->size_b > 1)
			search_min_a_to_b(stack);
		if (stack->stack_a->index == min)
			push_down(stack);
		else
			pb(stack, 1);
	}
}
