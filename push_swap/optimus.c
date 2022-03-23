/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   optimus.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 22:07:42 by drgnvgr           #+#    #+#             */
/*   Updated: 2022/03/24 00:02:59 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_el(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	if (stack->size_b == 0)
		return ;
	a = stack->stack_b->index;
	b = stack->stack_b->next->index;
	c = stack->stack_b->prev->index;
	if (b > a && b > c)
		rrb(stack, 1);
	else if (a > b && a > c)
		rb(stack, 1);
	a = stack->stack_b->index;
	b = stack->stack_b->next->index;
	if (a > b)
		sb(stack, 1);
}

void	five_el_first_ab(t_stack *stack, int flags)
{
	three_el(stack);
	if (stack->stack_a->index > stack->stack_a->next->index || \
		stack->stack_a->flags != flags)
		sa(stack, 1);
	while (stack->size_b != 0)
	{
		if (stack->stack_a->index > stack->stack_b->index || \
			stack->stack_a->flags != flags)
		{
			pa(stack, 1);
			push_down(stack);
		}
		else
			push_down(stack);
	}
	while (stack->stack_a->flags == flags && flags != -1)
		push_down(stack);
}

void	five_el_second_ab(t_stack *stack, int flags, int min, int i)
{
	t_node	*tmp;

	min = stack->stack_a->prev->index + 1;
	flags = stack->stack_a->flags;
	tmp = stack->stack_a;
	while (tmp->flags == flags && flags != -1)
	{
		tmp = tmp->next;
		i++;
	}
	if (i <= 5)
	{
		while (i > 2)
		{
			if (stack->stack_a->index == min)
			{
				push_down(stack);
				min++;
			}
			else
				pb(stack, 1);
			i--;
		}
		five_el_first_ab(stack, flags);
	}
}

void	five_el_first_ba(t_stack *stack, int flags)
{
	three_el(stack);
	if (stack->stack_a->index > stack->stack_a->next->index && \
		stack->stack_a->flags == stack->stack_a->next->flags)
		sa(stack, 1);
	while (stack->size_b != 0)
	{
		if (stack->stack_a->index > stack->stack_b->index || \
			stack->stack_a->flags == -1)
		{
			pa(stack, 1);
			push_down(stack);
		}
		else
			push_down(stack);
	}
	while (stack->stack_a->flags == flags && flags != -1 && \
		stack->stack_a->index + 1 == stack->stack_a->prev->index)
		push_down(stack);
}

void	five_el_second_ba(t_stack *stack)
{
	int		flags;
	int		min;
	int		i;
	t_node	*tmp;

	i = stack->size_b;
	min = stack->stack_a->prev->index + 1;
	flags = stack->stack_a->flags;
	tmp = stack->stack_a;
	while (i > 3)
	{
		if (stack->stack_b->index == min)
		{
			pa(stack, 1);
			push_down(stack);
			min++;
		}
		else
			pa(stack, 1);
		i--;
	}
	five_el_first_ba(stack, flags);
}
