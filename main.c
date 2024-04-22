/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:45:58 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/22 18:37:19 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void put_data(t_data *data, int argc, char **argv)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		num = ft_atol(argv[i]);
		if (num > INT_MAX || num < INT_MIN)
		{
			ft_putendl_fd("Error", 2);
			exit(1);
		}
		if (data->a == NULL)
			data->a = stack_new(num);
		else
			stack_add_back(data->a, stack_new(num));
		i++;
	}
}

static void compress_num(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = data->a;
	while (tmp)
	{
		tmp2 = data->a;
		while (tmp2)
		{
			if (tmp->origin_num >= tmp2->origin_num)
				tmp->compress_num++;
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
}

int main(int argc, char **argv)
{
	t_data	*data;

	if (argc < 2)
		return (0);
	data = data_init();
	if (arg_invalid(argc, argv))
		return (error_exit(data));
	put_data(data, argc, argv);
	compress_num(data);
	if (check_duplicate(data))
		return (error_exit(data));
	if (is_sorted(data))
		return (free_data(data), 0);
	sort(data);
	free_data(data);
	return (0);
}

// __attribute__((destructor)) static void destructor(void)
// {
//     system("leaks -q push_swap");
// }