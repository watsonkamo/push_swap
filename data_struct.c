/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:21:40 by emma              #+#    #+#             */
/*   Updated: 2024/04/22 18:35:23 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_data *data_init(void)
{
	t_data    *data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		exit(1);
	data->a = NULL;
	data->b = NULL;
	return (data);
}

void free_data(t_data *data)
{
	t_stack    *tmp;

	while (data->a)
	{
		tmp = data->a->next;
		free(data->a);
		data->a = tmp;
	}
	while (data->b)
	{
		tmp = data->b->next;
		free(data->b);
		data->b = tmp;
	}
	free(data);
}
