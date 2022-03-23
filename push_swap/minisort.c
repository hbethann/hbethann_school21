/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minisort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 05:47:45 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/23 23:52:02 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sort_true(t_stack *stack)
{
	int		i;
	t_node	*head;

	head = stack->stack_a;
	i = stack->size_a - 1;
	while (i-- > 0)
	{
		if (head->index > head->next->index)
			return (0);
		head = head->next;
	}
	return (1);
}

void	sort_three_a(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->stack_a->index;
	b = stack->stack_a->next->index;
	c = stack->stack_a->prev->index;
	if (b > a && b > c)
		rra(stack, 1);
	else if (a > b && a > c)
		ra(stack, 1);
	a = stack->stack_a->index;
	b = stack->stack_a->next->index;
	if (a > b)
		sa(stack, 1);
}

void	sort_three_b(t_stack *stack)
{
	int	a;
	int	b;
	int	c;
	int	i;

	a = stack->stack_b->index;
	b = stack->stack_b->next->index;
	c = stack->stack_b->prev->index;
	i = stack->size_b;
	if (b > a && b > c)
		rrb(stack, 1);
	else if (a > b && a > c)
		rb(stack, 1);
	if (a > b)
		sb(stack, 1);
	while (i-- > 0)
	{
		stack->stack_b->flags = -1;
		pa(stack, 1);
		ra(stack, 1);
	}
}

int	short_cut(t_stack *stack)
{
	int		i;
	int		j;
	t_node	*tmp;

	tmp = stack->stack_a;
	i = 0;
	while (i++)
	{
		if (tmp->index == stack->min)
			break ;
		tmp = tmp->next;
	}
	tmp = stack->stack_a;
	j = 0;
	while (j++)
	{
		if (tmp->index == stack->min)
			break ;
		tmp = tmp->next;
	}
	if (j >= i)
		return (1);
	return (0);
}

void	five_sort(t_stack *stack)
{
	while (stack->size_a > 3)
	{
		min_med_max_a(stack);
		if (stack->stack_a->index == stack->min)
		{
			pb(stack, 1);
			continue ;
		}
		if (short_cut(stack))
			ra(stack, 1);
		else
			rra(stack, 1);
	}
	sort_three_a(stack);
	pa(stack, 1);
	pa (stack, 1);
}
