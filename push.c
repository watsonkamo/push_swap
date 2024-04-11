#include "push_swap.h"

void pa(t_data *data)
{
    t_stack *top_b;

    top_b = data->b;
    if (data->b == NULL)
        return;
// スタックBから一番上の要素を削除
    data->b = data->b->next;
    if (data->b != NULL)
        data->b->prev = NULL;
// スタックAの一番上に元々スタックBの一番上だった要素を追加
    top_b->next = data->a;
    top_b->prev = NULL;
    if (data->a != NULL)
        data->a->prev = top_b;
    data->a = top_b;
    printf("pa\n");
}

void pb(t_data *data)
{
    t_stack *top_a;

    top_a = data->a;
    if (data->a == NULL)
        return;
    data->a = data->a->next;
    if (data->a != NULL)
        data->a->prev = NULL;
    top_a->next = data->b;
    top_a->prev = NULL;
    if (data->b != NULL)
        data->b->prev = top_a;
    data->b = top_a;
    printf("pb\n");
}
