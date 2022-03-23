/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:51:51 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/23 18:48:45 by hbethann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "libft/libft.h"

# define MAX_INT 2147483647
# define MIN_INT -2147483648

//struct of list
typedef struct s_node
{
	int				num;
	int				index;
	int				flags;
	struct s_node	*next;
	struct s_node	*prev;
}					t_node;

typedef struct s_stack
{
	t_node	*stack_a;
	t_node	*stack_b;
	int		size_a;
	int		size_b;
	int		min;
	int		med;
	int		max;
	int		min_a;
}			t_stack;

// init_stack.c
t_stack	*struct_init(char **array);
t_node	*new_list(int num, int index);
void	lstadd_back(t_node	**stack_a, t_node *new);
void	ft_free_stack(t_stack *stack);

// ft_check.c
void	twins(char **array);
char	**ft_line(char **argv);
void	check_arg(char **array);
void	free_array(char **array, int flag);
void	error(void);

// add_stack.c
void	stack_add(t_stack *stack, char **arr);
void	bubble_sorting(t_stack *stack, char *sort_arr,
			char *not_sort_arr, int len);
void	create_stack(t_stack *stack, char *sort_arr,
			char *not_sort_arr, int len);

// swap.c
void	sa(t_stack *stack, int flag);
void	sb(t_stack *stack, int flag);
void	ss(t_stack *stack, int flag);

// push_cmd.c
void	push_b(t_stack *stack);
void	push_a(t_stack *stack);
void	pb(t_stack *stack, int flag);
void	pa(t_stack *stack, int flag);

// rotate.c
void	ra(t_stack *stack, int flag);
void	rb(t_stack *stack, int flag);
void	rr(t_stack *stack, int flag);

// rev_rot.c
void	rra(t_stack *stack, int flag);
void	rrb(t_stack *stack, int flag);
void	rrr(t_stack *stack, int flag);

// minisort.c
int		sort_true(t_stack *stack);
void	sort_three_a(t_stack *stack);
void	sort_three_b(t_stack *stack);
int		shor_cut(t_stack *stack);
void	five_sort(t_stack *stack);

// medsort.c
void	min_med_max_a(t_stack *stack);
void	min_med_max_b(t_stack *stack);
void	move_down(t_stack *stack);
void	move_a_to_b_first(t_stack *stack);

// big_sort.c
void	push_down(t_stack *stack);
int		search_min_b_to_a(t_stack *stack);
void	move_b_to_a(t_stack *stack);
void	search_min_a_to_b(t_stack *stack);
void	move_a_to_b(t_stack *stack);

// optimus.c
int		three_el(t_stack *stack);
void	five_el_first_ab(t_stack *stack, int flags);
void	five_el_second_ab(t_stack *stack, int flags, int min, int i);
void	five_el_first_ba(t_stack *stack, int flags);
void	five_el_second_ba(t_stack *stack);

// cheker.c
t_stack	*parser(char **argv);

#endif