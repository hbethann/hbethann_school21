/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 13:32:50 by drgnvgr           #+#    #+#             */
/*   Updated: 2022/03/28 14:19:57 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	cmd(t_stack *stack, char *line)
{
	if (!ft_strncmp(line, "pa\n", 3))
		pa(stack, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		pb(stack, 0);
	else if (!ft_strncmp(line, "sa\n", 3))
		sa(stack, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		sb(stack, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		ss(stack, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		ra(stack, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rb(stack, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rr(stack, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		rra(stack, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		rrb(stack, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		rrr(stack, 0);
	else
		error();
}

static t_stack	*pars(char **argv)
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

static void	checker(t_stack *stack)
{
	char	*line;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break ;
		cmd(stack, line);
	}
	if (sort_true(stack))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int	main(int argc, char **argv)
{
	t_stack	*stack;

	if (argc > 1)
	{
		stack = pars(argv);
		checker(stack);
		ft_free_stack(stack);
	}
	return (0);
}
