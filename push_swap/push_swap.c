/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 19:29:33 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/23 21:38:55 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*parsing(char **argv)
{
	t_stack	*stack;
	char	**array;

	array = ft_line(argv);
	check_arg(array);
	twins(array);
	stack = struct_init(array);
	stack_add(stack, array);
	free_array(array, 0);
	return (stack);
}

void	sorting(t_stack *stack)
{
	if (sort_true(stack))
		ft_free_stack(stack);
	if (stack->size_a < 6)
	{
		five_sort(stack);
		ft_free_stack(stack);
	}
	move_a_to_b_first(stack);
	while (!(sort_true(stack) && stack->size_a == 0))
	{
		if (stack->size_b > 0 && stack->size_b < 6)
			five_el_second_ba(stack);
		else if (stack->size_b >= 6)
			move_a_to_b(stack);
		if (stack->size_b == 0)
		{
			five_el_second_ab(stack, 0, 0, 0);
			move_a_to_b(stack);
		}
	}
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc > 1)
	{
		stack = parser(argv);
		sorting(stack);
		ft_free_stack(stack);
	}
	return (0);
}