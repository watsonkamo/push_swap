/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:12:21 by emma              #+#    #+#             */
/*   Updated: 2024/04/22 18:14:47 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void send_to_b(t_data *data, int min, int pivot)
{
	int i;
	int len;
	int average;
	t_stack *tmp;

	i = 0;
    average = (pivot + min) / 2;
	len = stack_len(data->a);
	while (i < len)
	{
		tmp = data->a;
		if (tmp->compress_num <= pivot)
		{
			pb(data);
			if (tmp->compress_num <= average)
				rb(data);
		}
		else
			ra(data);
		i++;
	}
}

void send_to_b_all(t_data *data)
{
	int i;
	int len;

	i = 0;
	len = stack_len(data->a);
	while (i < len)
	{
		pb(data);
		i++;
	}
}

bool is_above_the_center(t_stack *stack, int num)
{
	t_stack *tmp = stack;
	t_stack *tmp2 = stack;

	while (tmp2->next != NULL)
		tmp2 = tmp2->next;
	while (tmp->next != NULL)
	{
		if (tmp->compress_num == num)
			return (true);
		if (tmp2->compress_num == num)
			return (false);
		tmp = tmp->next;
		tmp2 = tmp2->prev;
	}
	return (false);
}

# define division 8

void sort_large(t_data *data)
{
	int	pivot = -1;
	int min;

	int i = 1;
	while (i < division)
	{
		min = pivot + 1;
		pivot = find_max(data->a) / division * i;
		send_to_b(data, min, pivot);
		i++;
	}
	send_to_b_all(data);
	while (data->b != NULL)
	{
		if (data->b->compress_num == find_max(data->b))
			pa(data);
		else if (is_above_the_center(data->b, find_max(data->b)))
			rb(data);
		else 
			rrb(data);
	}
}

