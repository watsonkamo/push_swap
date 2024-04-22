/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:48:48 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 18:11:40 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int find_max(t_stack *stack)
{
	int max;
	t_stack *temp;

	if (stack == NULL)
	{
		ft_putendl_fd("Error: Stack is empty!", 2);
		return (-1);
	}
	max = stack->compress_num;
	temp = stack->next;
	while (temp && temp != stack)
	{
		if (temp->compress_num > max)
			max = temp->compress_num;
		temp = temp->next;
	}
	return (max);
}

int find_min(t_stack *stack)
{
	int min;
	t_stack *temp;

	if (stack == NULL)
	{
		ft_putendl_fd("Error: Stack is empty!", 2);
		return (-1);
	}
	min = stack->compress_num;
	temp = stack->next;
	while (temp && temp != stack)
	{
		if (temp->compress_num < min)
			min = temp->compress_num;
		temp = temp->next;
	}
	return (min);
}
