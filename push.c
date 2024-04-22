/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:47:58 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 18:20:11 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void pa(t_data *data)
{
	t_stack *top_b;

	top_b = data->b;
	if (data->b == NULL)
		return ;
	data->b = data->b->next;
	if (data->b != NULL)
		data->b->prev = NULL;
	top_b->next = data->a;
	top_b->prev = NULL;
	if (data->a != NULL)
		data->a->prev = top_b;
	data->a = top_b;
	ft_putendl_fd("pa", 1);
}

void pb(t_data *data)
{
	t_stack *top_a;

	top_a = data->a;
	if (data->a == NULL)
		return ;
	data->a = data->a->next;
	if (data->a != NULL)
		data->a->prev = NULL;
	top_a->next = data->b;
	top_a->prev = NULL;
	if (data->b != NULL)
		data->b->prev = top_a;
	data->b = top_a;
	ft_putendl_fd("pb", 1);
}
