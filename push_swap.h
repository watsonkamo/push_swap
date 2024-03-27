#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
# include "libft.h"

// typedef struct s_stack
// {
//     int *data;
//     int size;
// } t_stack;

typedef struct s_stack
{
	int *data;
    int size;
	struct s_stack      *next;
	struct s_stack      *prev;
	int                 origin_num;
	int                 compress_num;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

void	sort_2(t_data *data);
void	sort_3(t_data *data);
void	sort_4(t_data *data);
void	sort_5(t_data *data);
void	sort_large(t_data *data);
void sort(t_data *data);

t_data *data_init(void);
int arg_invalid(int argc, char **argv);
void free_data(t_data *data);
t_stack *stack_new(int num);
void stack_add_back(t_stack *stack, t_stack *new);
int stack_len(t_stack *stack);
int error_exit(t_data *data);
void put_data(t_data *data, int argc, char **argv);
void compress_num(t_data *data);
int is_sorted(t_data *data);
int check_duplicate(t_data *data);

void sa(t_data *data);
void sb(t_data *data);
void ss(t_data *data);

void pa(t_stack *stackA, t_stack *stackB);
void pb(t_stack *stackA, t_stack *stackB);

void ra(t_stack *stackA);
void rb(t_stack *stackB);
void rr(t_stack *stackA, t_stack *stackB);

void rra(t_stack *stackA);
void rrb(t_stack *stackB);
void rrr(t_stack *stackA, t_stack *stackB);

int find_max(t_stack *stack);
int find_min(t_stack *stack);
void quick_sort(int *arr, int start, int end);
void array_to_stack(t_data *data, int *arr, int len);
void stack_to_array(t_stack *stack, int *arr);
void sort_large_100(t_data *data);
void sort_large_500(t_data *data);

// この関数は提出の時は消すように！（debug 用）
void    check_stack(t_data *data);

#endif