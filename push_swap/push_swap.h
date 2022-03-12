/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbethann <hbethann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 14:51:51 by hbethann          #+#    #+#             */
/*   Updated: 2022/03/12 14:56:41 by hbethann         ###   ########.fr       */
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

#endif