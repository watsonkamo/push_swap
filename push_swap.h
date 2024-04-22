/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:47:17 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 18:46:01 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

# define DIVISION 8

typedef struct s_stack
{
	struct s_stack	*next;
	struct s_stack	*prev;
	int				origin_num;
	int				compress_num;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

// sort.c
void	sort(t_data *data);

// sort_small.c
void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	sort_4(t_data *data);
void	sort_5(t_data *data);

// sort_large.c
void	sort_large(t_data *data);

// arg_check.c
int		arg_invalid(int argc, char **argv);
int		check_duplicate(t_data *data);
int		is_sorted(t_data *data);

// data_struct.c
t_data	*data_init(void);
void	free_data(t_data *data);

// find_num.c
int		find_max(t_stack *stack);
int		find_min(t_stack *stack);

// push.c
void	pa(t_data *data);
void	pb(t_data *data);

// rotate.c
void	ra(t_data *data);
void	rb(t_data *data);
void	rr(t_data *data);

// rev_rotate.c
void	rra(t_data *data);
void	rrb(t_data *data);
void	rrr(t_data *data);

// swap.c
void	sa(t_data *data);
void	sb(t_data *data);
void	ss(t_data *data);

// stack_struct.c
t_stack	*stack_new(int num);
void	stack_add_back(t_stack *stack, t_stack *new);
int		stack_len(t_stack *stack);

// util.c
int		error_exit(t_data *data);

#endif