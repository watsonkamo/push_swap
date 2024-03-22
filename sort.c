#include "push_swap.h"

void sort_2(t_data *data)
{
	sa(data->a);
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
		rra(data->a);
	else if (b < a && a < c)
		sa(data->a);
	else if (b < c && c < a)
	{
		sa(data->a);
		ra(data->a);
	}
	else if (c < a && a < b)
		rra(data->a);
	else
	{
		sa(data->a);
		rra(data->a);
	}
}

void sort_4(t_data *data)
{
	int    min;
	int    max;
printf("%s\n", "check_sort_4-1");
	min = find_min(data->a);
	max = find_max(data->a);
	while (data->a->compress_num != min && data->a->compress_num != max)
		ra(data->a);
	if (data->a->compress_num == max)
		sa(data->a);
	pb(data->a, data->b);
	sort_3(data);//ここまでおk
	pa(data->a, data->b);//こいつがセグフォしてる。pa,pbあたりの引数の渡し方に問題がありそう
	printf("%s\n", "check_sort_4-2");
}


void sort_5(t_data *data)
{
	int    min;
	int    max;

	min = find_min(data->a);
	max = find_max(data->a);
	while (data->a->compress_num != min && data->a->compress_num != max)
		ra(data->a);
	if (data->a->compress_num == max)
		sa(data->a);
	pb(data->a, data->b);
	sort_4(data);//こいつがセグフォしてるというかsort4がセグフォなのでそこを直す
	//printf("%s\n", "check_sort_5");
	pa(data->a, data->b);
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
printf("%s", "test");
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

int find_max(t_stack *stack)
{
	int    max;
	t_stack    *temp;

	max = stack->compress_num;
	temp = stack->next;
	while (temp)
	{
		if (temp->compress_num > max)
			max = temp->compress_num;
		temp = temp->next;
	}
	return (max);
}

int find_min(t_stack *stack)
{
	int    min;
	t_stack    *temp;

	min = stack->compress_num;
	temp = stack->next;
	while (temp)
	{
		if (temp->compress_num < min)
			min = temp->compress_num;
		temp = temp->next;
	}
	return (min);
}

void stack_to_array(t_stack *stack, int *arr)
{
	int    i;

	i = 0;
	while (stack)
	{
		arr[i] = stack->compress_num;
		stack = stack->next;
		i++;
	}
}

void array_to_stack(t_data *data, int *arr, int len)
{
	int    i;

	i = 0;
	while (i < len)
	{
		stack_add_back(data->a, stack_new(arr[i]));
		i++;
	}
}

void quick_sort(int *arr, int start, int end)
{
	int    pivot;
	int    left;
	int    right;
	int    temp;

	if (start >= end)
		return ;
	pivot = start;
	left = start + 1;
	right = end;
	while (left <= right)
	{
		while (left <= end && arr[left] <= arr[pivot])
			left++;
		while (right > start && arr[right] >= arr[pivot])
			right--;
		if (left > right)
		{
			temp = arr[right];
			arr[right] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			temp = arr[left];
			arr[left] = arr[right];
			arr[right] = temp;
		}
	}
	quick_sort(arr, start, right - 1);
	quick_sort(arr, right + 1, end);
}

void sort_large_100(t_data *data)
{
	int    i;
	int    len;
	int    chunk;
	int    *arr;

	len = stack_len(data->a);
	chunk = len / 5;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return ;
	i = 0;
	while (i < 5)
	{
		if (i == 4)
			chunk = len - (chunk * 4);
		arr = (int *)malloc(sizeof(int) * chunk);
		if (!arr)
			return ;
		stack_to_array(data->a, arr);
		quick_sort(arr, 0, chunk - 1);
		array_to_stack(data, arr, chunk);
		free(arr);
		i++;
	}
}

void sort_large_500(t_data *data)
{
	int    i;
	int    len;
	int    chunk;
	int    *arr;

	len = stack_len(data->a);
	chunk = len / 11;
	arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return ;
	i = 0;
	while (i < 11)
	{
		if (i == 10)
			chunk = len - (chunk * 10);
		arr = (int *)malloc(sizeof(int) * chunk);
		if (!arr)
			return ;
		stack_to_array(data->a, arr);
		quick_sort(arr, 0, chunk - 1);
		array_to_stack(data, arr, chunk);
		free(arr);
		i++;
	}
}