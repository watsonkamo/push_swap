/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emma <emma@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 18:22:44 by emma              #+#    #+#             */
/*   Updated: 2024/04/22 19:11:16 by emma             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	arg_invalid(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		if (ft_strlen(argv[i]) > 11)
			return (1);
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (j != 0 || argv[i][j + 1] == '\0')
					return (1);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && \
				argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicate(t_data *data)
{
	t_stack	*tmp;
	t_stack	*tmp2;

	tmp = data->a;
	while (tmp)
	{
		tmp2 = tmp->next;
		while (tmp2)
		{
			if (tmp->origin_num == tmp2->origin_num)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp = tmp->next;
	}
	return (0);
}

int	is_sorted(t_data *data)
{
	t_stack	*tmp;

	tmp = data->a;
	while (tmp->next)
	{
		if (tmp->origin_num > tmp->next->origin_num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}
