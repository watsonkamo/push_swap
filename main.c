/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eshintan <eshintan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 18:45:58 by eshintan          #+#    #+#             */
/*   Updated: 2024/04/18 18:45:59 by eshintan         ###   ########.fr       */
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


int arg_invalid(int argc, char **argv)
{
	int    i;
	int    j;

	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == '-' || argv[i][j] == '+')
				if (j != 0)
					return (1);
			if (!ft_isdigit(argv[i][j]) && argv[i][j] != '-' && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
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

// void stack_add_back(t_stack **stack, t_stack *new)
// {
//     t_stack    *tmp;

//     if (*stack == NULL) // スタックが空の場合
//     {
//         *stack = new; // 新しいノードをスタックの先頭にする
//         new->prev = NULL; // 新しいノードの前はNULL
//     }
//     else
//     {
//         tmp = *stack;
//         while (tmp->next != NULL) // スタックの最後まで移動
//             tmp = tmp->next;
//         tmp->next = new; // 新しいノードを最後に追加
//         new->prev = tmp; // 新しいノードの前を設定
//     }
// }


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

int error_exit(t_data *data)
{
	free_data(data);
	ft_putendl_fd("Error", 2);
	return (1);
}


void put_data(t_data *data, int argc, char **argv)
{
	int    i;
	int    num;

	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		if (data->a == NULL)
			data->a = stack_new(num);
		else
			stack_add_back(data->a, stack_new(num));
		i++;
	}
}

void compress_num(t_data *data)
{
	t_stack    *tmp;
	t_stack    *tmp2;

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

int is_sorted(t_data *data)
{
	t_stack    *tmp;

	tmp = data->a;
	while (tmp->next)
	{
		if (tmp->origin_num > tmp->next->origin_num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int check_duplicate(t_data *data)
{
	t_stack    *tmp;
	t_stack    *tmp2;

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

int main(int argc, char **argv)
{
	t_data    *data;
	if (argc < 2)
		return (0);
	data = data_init();// malloc struct and put NULL to a and b 
	if (arg_invalid(argc, argv))// 数値以外が含まれている場合はエラー
		return (error_exit(data)); // error は終了ステータスを1にする
	put_data(data, argc, argv);// put data to a
	compress_num(data); // compress number
	if (is_sorted(data)) // すでにソートされている場合は何もしない
	{
		free_data(data);
		return (0);
	}
	if (check_duplicate(data)) // ./push_swap "1 1 2" とかはエラー
		return (error_exit(data)); // error は終了ステータスを1にする
	//printf("---start_sort---\n");
	//check_stack(data);
	sort(data);
	//printf("--- end_sort ---\n");
	// check_stack(data);
	free_data(data);
	return (0);
}

// __attribute__((destructor)) static void destructor(void)
// {
//     system("leaks -q push_swap");
// }