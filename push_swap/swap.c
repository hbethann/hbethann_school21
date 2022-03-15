/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 01:01:24 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/15 05:35:10 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack *stack, int flag)
{
	int	tmp;

	if (stack->size_a < 2)
		return ;
	tmp = stack->stack_a->num;
	stack->stack_a->next->num = tmp;
	tmp = stack->stack_a->index;
	stack->stack_a->index = stack->stack_a->next->index;
	stack->stack_a->next->index = tmp;
	if (flag)
		write(1, "sa\n", 3);
}

void	sb(t_stack *stack, int flag)
{
	int	tmp;

	if (stack->size_b < 2)
		return ;
	tmp = stack->stack_b->num;
	stack->stack_b->next->num = tmp;
	tmp = stack->stack_b->index;
	stack->stack_b->index = stack->stack_b->next->index;
	stack->stack_b->next->index = tmp;
	if (flag)
		write(1, "sb\n", 3);
}

void	ss(t_stack *stack, int flag)
{
	if (stack->size_a < 2 && stack->size_b < 2)
	{
		sa(stack, 0);
		sb(stack, 0);
		if (flag)
			write(1, "ss\n", 3);
	}
}
 