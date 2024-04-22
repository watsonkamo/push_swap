/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:48:27 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 19:06:14 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	first = data->a;
	last = data->a;
	if (data->a == NULL || data->a->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	data->a = first->next;
	data->a->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_putendl_fd("ra", 1);
}

void	rb(t_data *data)
{
	t_stack	*first;
	t_stack	*last;

	first = data->b;
	last = data->b;
	if (data->b == NULL || data->b->next == NULL)
		return ;
	while (last->next != NULL)
		last = last->next;
	data->b = first->next;
	data->b->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
	ft_putendl_fd("rb", 1);
}

void	rr(t_data *data)
{
	ra(data);
	rb(data);
	ft_putendl_fd("rr", 1);
}
