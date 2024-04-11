#include "push_swap.h"

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

void sort_large_100(t_data *data)
{
	int len;
	int *arr;

    len = stack_len(data->a);
    arr = (int *)malloc(sizeof(int) * len);
	if (!arr)
		return;
	stack_to_array(data->a, arr);
	quick_sort(arr, 0, len - 1);
	array_to_stack(data, arr, len);
	free(arr);
}

void swap(int* a, int* b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];  
    int i = (low - 1);  

    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++; 
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);

        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
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

