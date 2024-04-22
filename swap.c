/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:49:17 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 18:07:40 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    format_data(t_data *data)
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

void sa(t_data *data)
{
	t_stack *stackA;
	t_stack *tmp;

	stackA = data->a;
	if (stackA == NULL)
		return ;
	if (stack_len((stackA)) < 2)
		return ;
	tmp = stackA->next;
	stackA->next = tmp->next;
	tmp->next = stackA;
	tmp->prev = NULL;
	stackA->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	format_data(data);
	ft_putendl_fd("sa", 1);
}

void sb(t_data *data)
{
	t_stack *stackB;
	t_stack *tmp;

	stackB = data->b;
	if (stackB == NULL)
		return ;
	if (stack_len((stackB)) < 2)
		return ;
	tmp = stackB->next;
	stackB->next = tmp->next;
	tmp->next = stackB;
	tmp->prev = NULL;
	stackB->prev = tmp;
	if (tmp->next != NULL)
		tmp->next->prev = tmp;
	format_data(data);
	ft_putendl_fd("sb", 1);
}

void ss(t_data *data)
{
	sa(data);
	sb(data);
	ft_putendl_fd("ss", 1);
}
