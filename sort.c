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
	{
		ra(data);
	}
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

void send_to_b(t_data *data, int pivot)
{
	int i;
	int len;
	t_stack *tmp;

	i = 0;
	len = stack_len(data->a);
	while (i < len)
	{
		tmp = data->a;
		if (tmp->compress_num <= pivot)
			pb(data);
		else
			ra(data);
		i++;
	}
}

void send_to_b_all(t_data *data)
{
	int i;
	int len;
	// t_stack *tmp;

	i = 0;
	len = stack_len(data->a);
	while (i < len)
	{
		// tmp = data->a;
		pb(data);
		i++;
	}
}

void sort_large(t_data *data)
{
	// quick sort を使いたい

	// 基準の値を決める
	int	pivot;
	pivot = find_max(data->a) / 2;
	// 全体の数を見て中央値以下の時 a->b
	// それ以外の時 a->a
	// 送り終わったら a->b
	send_to_b(data, pivot);
	send_to_b_all(data);
	// bの中の最大値のみをaに送る
	// bの最大値が上半分にあるか下半分にあるかで処理を変える
	// 上半分の時 最大値が一番上に来るまでrb
	// 下半分の時 最大値が一番上に来るまでrrb
	while (data->b != NULL)
	{
		if (data->b->compress_num == find_max(data->b))
			pa(data);
		else
			rb(data);
	}
}

// void sort_large(t_data *data)
// {
// 	int i;
// 	int size;
// 	t_stack *tmp;

// 	i = 0;
// 	size = stack_len(data->a);
// 	//ft_partition(data);
// 	while (i < compress_num && data->a->compress_num > 5)
// 	{
// 		tmp = find_min(data->a);
// 		if (tmp->data <= data->a->data[1])
// 		{
// 			pb(data);
// 			if (tmp->data <= data->a->data[0])
// 				rb(data);
// 		}
// 		else
// 			ra(data);
// 		i++;
// 	}
// 	while (data->a->compress_num > 5)
// 		pb(data);
// }

void sort(t_data *data)
{
	int    len;
	len = stack_len(data->a);
	if (len == 2)
		sort_2(data);
	else if (len == 3)
		sort_3(data);
	else if (len == 4)
		sort_4(data);
	else if (len == 5)
		sort_5(data);
	else
		sort_large(data);
}
