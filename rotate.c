#include "push_swap.h"

void ra(t_data *data)
{
    t_stack *first;
    t_stack *last;

    first = data->a;
    last = data->a;
    if (data->a == NULL || data->a->next == NULL)
        return;
// 最後のノードを見つける
    while (last->next != NULL)
    {
        last = last->next;
    }
// 元の最初のノードを新しい最後のノードに更新
    data->a = first->next; // 新しい最初のノードを設定
    data->a->prev = NULL; // 新しい最初のノードのprevをNULLに設定
// 元の最初のノード（新しい最後のノード）を最後に接続
    last->next = first; // 元の最後のノード（新しい最後から2番目のノード）のnextを元の最初のノード（新しい最後のノード）に設定
    first->prev = last; // 新しい最後のノードのprevを元の最後のノード（新しい最後から2番目のノード）に設定
    first->next = NULL; // 新しい最後のノードのnextをNULLに設定
}

void rb(t_data *data)
{
    t_stack *first;
    t_stack *last;

    first = data->b;
    last = data->b;
    if (data->b == NULL || data->b->next == NULL)
        return;
// 最後のノードを見つける
    while (last->next != NULL)
    {
        last = last->next;
    }
// 元の最初のノードを新しい最後のノードに更新
    data->b = first->next; // 新しい最初のノードを設定
    data->b->prev = NULL; // 新しい最初のノードのprevをNULLに設定
// 元の最初のノード（新しい最後のノード）を最後に接続
    last->next = first; // 元の最後のノード（新しい最後から2番目のノード）のnextを元の最初のノード（新しい最後のノード）に設定
    first->prev = last; // 新しい最後のノードのprevを元の最後のノード（新しい最後から2番目のノード）に設定
    first->next = NULL; // 新しい最後のノードのnextをNULLに設定
}

void rr(t_data *data)
{
    ra(data);
    rb(data);
}