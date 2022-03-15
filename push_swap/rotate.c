/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 00:32:41 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/15 00:40:36 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *stack, int flag)
{
	if (stack->size_a > 1)
		stack->stack_a = stack->stack_a->next;
	if (flag)
		write(1, "ra\n", 3);
}

void	rb(t_stack *stack, int flag)
{
	if (stack->size_b > 1)
		stack->stack_b = stack->stack_b->next;
	if (flag)
		write(1, "rb\n", 3);
}

void	rr(t_stack *stack, int flag)
{
	if (stack->size_a > 1 && stack->size_b > 1)
	{
		ra(stack, 0);
		rb(stack, 0);
		if (flag)
			write(1, "rr\n", 3);
	}
}
