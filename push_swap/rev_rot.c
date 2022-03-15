/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:41:59 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/15 00:43:10 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack *stack, int flag)
{
	if (stack->size_a > 1)
		stack->stack_a = stack->stack_a->prev;
	if (flag)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *stack, int flag)
{
	if (stack->size_b > 1)
		stack->stack_b = stack->stack_b->prev;
	if (flag)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *stack, int flag)
{
	if (stack->size_a > 1 && stack->size_b > 1)
	{
		rra(stack, 0);
		rrb(stack, 0);
		if (flag)
			write(1, "rrr\n", 4);
	}
}
