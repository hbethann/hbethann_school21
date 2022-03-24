/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 20:17:04 by drgnvgr           #+#    #+#             */
/*   Updated: 2022/03/24 19:11:39 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*struct_init(char **array)
{
	t_stack	*stacks;
	int		i;

	i = 0;
	while (array[i])
		i++;
	stacks = malloc(sizeof(t_stack));
	if (stacks == NULL)
		return (NULL);
	stacks->stack_a = NULL;
	stacks->stack_b = NULL;
	stacks->size_a = i;
	stacks->size_b = 0;
	stacks->min_a = 1;
	return (stacks);
}

t_node	*new_list(int num, int index)
{
	t_node	*list;

	list = malloc(sizeof(t_node));
	if (list == NULL)
		return (NULL);
	list->num = num;
	list->flags = 0;
	list->index = index;
	list->next = NULL;
	list->prev = NULL;
	return (list);
}

/* изменяем указатель на следующий лист у пердудущего элемента стэка
			"inception->prev->next = new;" 					*/
void	lstadd_back(t_node	**stack_a, t_node *new)
{
	t_node	*inception;

	if (new == NULL)
		return ;
	inception = *stack_a;
	if (inception)
	{
		if (inception->prev)
		{
			inception->prev->next = new;
			new->prev = inception->prev;
			new->next = inception;
			inception->prev = new;
		}
		else
		{
			inception->prev = new;
			inception->next = new;
			new->prev = inception;
			new->next = inception;
		}
	}
	else
		*stack_a = new;
	return ;
}

void	ft_free_stack(t_stack *stack)
{
	t_node	*tmp;

	while (stack->size_a--)
	{
		tmp = stack->stack_a->next;
		free(stack->stack_a);
		stack->stack_a = NULL;
		stack->stack_a = tmp;
	}
	while (stack->size_b--)
	{
		tmp = stack->stack_b->next;
		free(stack->stack_b);
		stack->stack_b = NULL;
		stack->stack_b = tmp;
	}
	free(stack);
	exit (0);
}
