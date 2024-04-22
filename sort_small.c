/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:49:01 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 18:13:33 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_2(t_data *data)
{
	sa(data);
}

void sort_3(t_data *data)
{
	int    a;
	int    b;
	int    c;

	a = data->a->compress_num;
	b = data->a->next->compress_num;
	c = data->a->next->next->compress_num;
	if (a < b && b < c)
		return ;
	else if (a < c && c < b)
	{
		sa(data);
		ra(data);
	}
	else if (b < a && a < c)
		sa(data);
	else if (b < c && c < a)
		ra(data);
	else if (c < a && a < b)
		rra(data);
	else if(c < b && b < a)
	{
		sa(data);
		rra(data);
	}
}

void sort_4(t_data *data)
{
	t_stack *tmp;
	int min;

	tmp = data->a;
	min = find_min(tmp);
	while (tmp->compress_num != min)
	{
		ra(data);
		tmp = data->a;
	}
	pb(data);
	sort_3(data);
	pa(data);
}

void sort_5(t_data *data)
{
	int    min;

	min = find_min(data->a);
	if (data->a->compress_num == min)
		;
	else if (data->a->next->compress_num == min)
		ra(data);
	else if (data->a->next->next->compress_num == min)
	{
		ra(data);
		ra(data);
	}
	else
	{
		while (data->a->compress_num != min)
			rra(data);
	}
	pb(data);
	sort_4(data);
	pa(data);
}
