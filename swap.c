/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:49:17 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 18:51:35 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	format_data(t_data *data)
{
	if (data == NULL)
		return ;
	if (data->a != NULL)
		while (data->a->prev)
			data->a = data->a->prev;
	if (data->b != NULL)
		while (data->b->prev)
			data->b = data->b->prev;
}

void	sa(t_data *data)
{
	t_stack	*stack_a;
	t_stack	*tmp;

	stack_a = data->a;
	if (stack_a == NULL)
		return ;
	if (stack_len(stack_a) < 2)
		return ;
	tmp = stack_a->next;
	stack_a->next = tmp->next;
	tmp->next = stack_a;
	tmp->prev = NULL;
	stack_a->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	format_data(data);
	ft_putendl_fd("sa", 1);
}

void	sb(t_data *data)
{
	t_stack	*stack_b;
	t_stack	*tmp;

	stack_b = data->b;
	if (stack_b == NULL)
		return ;
	if (stack_len(stack_b) < 2)
		return ;
	tmp = stack_b->next;
	stack_b->next = tmp->next;
	tmp->next = stack_b;
	tmp->prev = NULL;
	stack_b->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	format_data(data);
	ft_putendl_fd("sb", 1);
}

void	ss(t_data *data)
{
	sa(data);
	sb(data);
	ft_putendl_fd("ss", 1);
}
