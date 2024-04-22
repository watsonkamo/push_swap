/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:48:07 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 18:20:01 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rra(t_data *data)
{
	t_stack *last;
	t_stack *prev;

	last = data->a;
	prev = NULL;
	if (data->a == NULL || data->a->next == NULL)
		return ;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = data->a;
	data->a->prev = last;
	last->prev = NULL;
	data->a = last;
	ft_putendl_fd("rra", 1);
}

void rrb(t_data *data)
{
	t_stack *last;
	t_stack *prev;

	last = data->b;
	prev = NULL;
	if (data->b == NULL || data->b->next == NULL)
		return ;
	while (last->next != NULL)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = data->b;
	data->b->prev = last;
	last->prev = NULL;
	data->b = last;
	ft_putendl_fd("rrb", 1);
}

void rrr(t_data *data)
{
	rra(data);
	rrb(data);
	ft_putendl_fd("rrr", 1);
}
