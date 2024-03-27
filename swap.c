#include "push_swap.h"

void    format_data(t_data *data)
{
    if (data == NULL)
        return ;
    if (data->a != NULL)
        while (data->a->prev)
            data->a = data->a->prev;
    if (data->b != NULL)
        while (data->b->prev)
            data->b = data->b->prev;
}

void sa(t_data *data)
{
    t_stack *stackA;
    t_stack *tmp;

    stackA = data->a;
    if (stackA == NULL)
        return ;
    if (stack_len((stackA)) < 2)
        return ;
    tmp = stackA->next;
    stackA->next = tmp->next;
    tmp->next = stackA;
    tmp->prev = NULL;
    stackA->prev = tmp;
    if (tmp->next != NULL)
        tmp->next->prev = tmp;
    format_data(data);
}

void sb(t_data *data)
{
    t_stack *stackB;
    t_stack *tmp;

    stackB = data->b;
    if (stackB == NULL)
        return ;
    if (stack_len((stackB)) < 2)
        return ;
    tmp = stackB->next;
    stackB->next = tmp->next;
    tmp->next = stackB;
    tmp->prev = NULL;
    stackB->prev = tmp;
    if (tmp->next != NULL)
        tmp->next->prev = tmp;
    format_data(data);
}

void ss(t_data *data)
{
    sa(data);
    sb(data);
}

void pa(t_stack *stackA, t_stack *stackB)
{
    if (stackA == NULL || stackB == NULL) // NULLポインタチェック
        return;
    
    if (stackB->size < 1)
        return;

    // stackAが空の場合の処理を追加
    if (stackA->size == 0) {
        stackA->data[0] = stackB->data[0];
    } else {
        int i = stackA->size;
        while (i > 0)
        {
            stackA->data[i] = stackA->data[i - 1];
            i--;
        }
        stackA->data[0] = stackB->data[0];
    }

    // stackBの要素を前に詰める処理を修正
    int i = 0;
    while (i < stackB->size - 1)
    {
        stackB->data[i] = stackB->data[i + 1];
        i++;
    }
    stackA->size += 1;
    stackB->size -= 1;
}

// void pa(t_stack *stackA, t_stack *stackB)
// {
//     int i;

//     if (stackB->size < 1)
//         return;
//     i = stackA->size;
//     while (i > 0)
//     {
//         stackA->data[i] = stackA->data[i - 1];
//         i--;
//     }
//     stackA->data[0] = stackB->data[0];
//     i = 0;
//     while (i < stackB->size - 1)
//     {
//         stackB->data[i] = stackB->data[i + 1];
//         i++;
//     }
//     stackA->size += 1;
//     stackB->size -= 1;
// }

void pb(t_stack *stackA, t_stack *stackB)
{
    int i;

    if (stackA->size < 1)
        return;
    i = stackB->size; 
    while (i > 0)
    {
        stackB->data[i] = stackB->data[i - 1];
        i--;
    }
    stackB->data[0] = stackA->data[0];
    i = 0;
    while (i < stackA->size - 1)
    {
        stackA->data[i] = stackA->data[i + 1];
        i++;
    }
    stackB->size += 1;
    stackA->size -= 1;
}

void ra(t_stack *stackA)
{
    int i;
    int temp;

    if (stackA->size < 2)
        return;

    temp = stackA->data[0];
    i = 0;
    while (i < stackA->size - 1)
    {
        stackA->data[i] = stackA->data[i + 1];
        i++;
    }
    stackA->data[stackA->size - 1] = temp;
}

void rb(t_stack *stackB)
{
    int i;
    int temp;

    if (stackB->size < 2)
        return;

    temp = stackB->data[0];
    i = 0;
    while (i < stackB->size - 1)
    {
        stackB->data[i] = stackB->data[i + 1];
        i++;
    }
    stackB->data[stackB->size - 1] = temp;
}

void rr(t_stack *stackA, t_stack *stackB)
{
    ra(stackA);
    rb(stackB);
}

void rra(t_stack *stackA)
{
    int i;
    int temp;

    if (stackA->size < 2)
        return;
    temp = stackA->data[stackA->size - 1];
    i = stackA->size - 1;
    while (i > 0)
    {
        stackA->data[i] = stackA->data[i - 1];
        i--;
    }
    stackA->data[0] = temp;
}

void rrb(t_stack *stackB)
{
    int i;
    int temp;

    if (stackB->size < 2)
        return;
    temp = stackB->data[stackB->size - 1];
    i = stackB->size - 1;
    while (i > 0)
    {
        stackB->data[i] = stackB->data[i - 1];
        i--;
    }
    stackB->data[0] = temp;
}

void rrr(t_stack *stackA, t_stack *stackB)
{
    rra(stackA);
    rrb(stackB);
}

// void sa(int *stackA, int size)
// {
//     int temp;

//     if (size < 2)
//         return;

//     temp = stackA[0];
//     stackA[0] = stackA[1];
//     stackA[1] = temp;
// }

// void sb(int *stackB, int size)
// {
//     int temp;

//     if (size < 2)
//         return;

//     temp = stackB[0];
//     stackB[0] = stackB[1];
//     stackB[1] = temp;
// }

// void ss(int *stackA, int sizeA, int *stackB, int sizeB)
// {
//     sa(stackA, sizeA);
//     sb(stackB, sizeB);
// }

// void pa(int *stackA, int *stackB, int *sizeA, int *sizeB)
// {
//     int i;

//     if (*sizeB < 1)
//         return;

//     for (i = *sizeA; i > 0; i--)
//         stackA[i] = stackA[i - 1];
//     stackA[0] = stackB[0];
//     for (i = 0; i < *sizeB - 1; i++)
//         stackB[i] = stackB[i + 1];
//     *sizeA += 1;
//     *sizeB -= 1;
// }

// void pb(int *stackA, int *stackB, int *sizeA, int *sizeB)
// {
//     int i;

//     if (*sizeA < 1)
//         return;

//     for (i = *sizeB; i > 0; i--)
//         stackB[i] = stackB[i - 1];
//     stackB[0] = stackA[0];
//     for (i = 0; i < *sizeA - 1; i++)
//         stackA[i] = stackA[i + 1];
//     *sizeB += 1;
//     *sizeA -= 1;
// }

// void ra(int *stackA, int size)
// {
//     int i;
//     int temp;

//     if (size < 2)
//         return;

//     temp = stackA[0];
//     for (i = 0; i < size - 1; i++)
//         stackA[i] = stackA[i + 1];
//     stackA[size - 1] = temp;
// }

// void rb(int *stackB, int size)
// {
//     int i;
//     int temp;

//     if (size < 2)
//         return;

//     temp = stackB[0];
//     for (i = 0; i < size - 1; i++)
//         stackB[i] = stackB[i + 1];
//     stackB[size - 1] = temp;
// }

// void rr(int *stackA, int sizeA, int *stackB, int sizeB)
// {
//     ra(stackA, sizeA);
//     rb(stackB, sizeB);
// }

// void rra(int *stackA, int size)
// {
//     int i;
//     int temp;

//     if (size < 2)
//         return;
//     temp = stackA[size - 1];
//     for (i = size - 1; i > 0; i--)
//         stackA[i] = stackA[i - 1];
//     stackA[0] = temp;
// }

// void rrb(int *stackB, int size)
// {
//     int i;
//     int temp;

//     if (size < 2)
//         return;
//     temp = stackB[size - 1];
//     for (i = size - 1; i > 0; i--)
//         stackB[i] = stackB[i - 1];
//     stackB[0] = temp;
// }

// void rrr(int *stackA, int sizeA, int *stackB, int sizeB)
// {
//     rra(stackA, sizeA);
//     rrb(stackB, sizeB);
// }
