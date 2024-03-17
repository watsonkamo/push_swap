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
		rra(data);
	else if (b < a && a < c)
		sa(data);
	else if (b < c && c < a)
	{
		sa(data);
		ra(data);
	}
	else if (c < a && a < b)
		rra(data);
	else
	{
		sa(data);
		rra(data);
	}
}

void sort_4(t_data *data)
{
	int    min;
	int    max;

	min = find_min(data->a);
	max = find_max(data->a);
	while (data->a->compress_num != min && data->a->compress_num != max)
		ra(data);
	if (data->a->compress_num == max)
		sa(data);
	pb(data);
	sort_3(data);
	pa(data);
}

void sort_5(t_data *data)
{
	int    min;
	int    max;

	min = find_min(data->a);
	max = find_max(data->a);
	while (data->a->compress_num != min && data->a->compress_num != max)
		ra(data);
	if (data->a->compress_num == max)
		sa(data);
	pb(data);
	sort_4(data);
	pa(data);
}

void sort_large(t_data *data)
{
	int    len;
	int    *arr;

	len = stack_len(data->a);
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return ;
	stack_to_array(data->a, arr);
	quick_sort(arr, 0, len - 1);
	array_to_stack(data, arr, len);
	free(arr);
	if (len < 100)
		sort_large_100(data);
	else
		sort_large_500(data);
}

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