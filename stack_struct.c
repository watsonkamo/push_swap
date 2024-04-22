/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:24:04 by emma              #+#    #+#             */
/*   Updated: 2024/04/22 18:25:24 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack *stack_new(int num)
{
	t_stack    *new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		exit(1);
	new->next = NULL;
	new->prev = NULL;
	new->origin_num = num;
	new->compress_num = 0;
	return (new);
}

void stack_add_back(t_stack *stack, t_stack *new)
{
	t_stack    *tmp;

	tmp = stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

int stack_len(t_stack *stack)
{
	int    len;

	len = 0;
	while (stack)
	{
		len++;
		stack = stack->next;
	}
	return (len);
}
