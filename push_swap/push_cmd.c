/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 22:18:50 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/15 08:24:38 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_b(t_stack *stack)
{
	t_stack	*buf;

	buf = stack->stack_a->next;
	stack->stack_a->prev->next = stack->stack_a->next;
	stack->stack_a->next->prev = stack->stack_a->prev;
	if (stack->stack_b)
	{
		stack->stack_a->prev = stack->stack_b->prev;
		stack->stack_a->next = stack->stack_b;
		stack->stack_b->prev->next = stack->stack_a;
		stack->stack_b = stack->stack_a;
	}
	else
	{
		stack->stack_b = stack->stack_a;
		stack->stack_a->next = stack->stack_b;
		stack->stack_a->prev = stack->stack_b;
	}
	stack->stack_a = buf;
	stack->stack_a->next->next->prev->prev;
	stack->stack_a->next->prev->next->prev;
}

void	push_a(t_stack *stack)
{
	t_stack	*buf;

	buf = stack->stack_b->next;
	stack->stack_b->prev->next = stack->stack_b->next;
	stack->stack_b->next->prev = stack->stack_b->prev;
	if (stack->stack_a)
	{
		stack->stack_b->prev = stack->stack_a->prev;
		stack->stack_b->next = stack->stack_a;
		stack->stack_a->prev->next = stack->stack_b;
		stack->stack_a = stack->stack_b;
	}
	else
	{
		stack->stack_a = stack->stack_b;
		stack->stack_a->next = stack->stack_a;
		stack->stack_a->prev = stack->stack_a;
	}
	stack->stack_b = buf;
}

void	pb(t_stack *stack, int flag)
{
	if (stack->stack_a == 0)
		return ;
	push_b(stack);
	if (stack->size_a == 1)
		stack->stack_a = NULL;
	stack->size_a--;
	stack->size_b++;
	if (flag)
		write(1, "pb\n", 3);
}

void	pa(t_stack *stack, int flag)
{
	if (stack->stack_b == 0)
		return ;
	push_b(stack);
	if (stack->size_b == 1)
		stack->stack_b = NULL;
	stack->size_b--;
	stack->size_a++;
	if (flag)
		write(1, "pa\n", 3);
}
