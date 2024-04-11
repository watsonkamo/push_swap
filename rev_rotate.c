#include "push_swap.h"

void rra(t_data *data)
{
    t_stack *last;
    t_stack *prev;

    last = data->a;
    prev = NULL;
    if (data->a == NULL || data->a->next == NULL)
        return;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL; // 新しい最後のノードのnextをNULLに設定
    last->next = data->a; // 元々の最後のノード（新しい最初のノード）のnextを元々の最初のノードに設定
    data->a->prev = last; // 元々の最初のノード（新しい最後のノード）のprevを元々の最後のノード（新しい最初のノード）に設定
    last->prev = NULL; // 新しい最初のノードのprevをNULLに設定
    data->a = last; // 最初のノードを更新
}

void rrb(t_data *data)
{
    t_stack *last;
    t_stack *prev;

    last = data->b;
    prev = NULL;
    if (data->b == NULL || data->b->next == NULL)
        return;
    while (last->next != NULL)
    {
        prev = last;
        last = last->next;
    }
    prev->next = NULL;
    last->next = data->b;
    data->b->prev = last;
    last->prev = NULL;
    data->b = last;
}

void rrr(t_data *data)
{
    rra(data);
    rrb(data);
}
