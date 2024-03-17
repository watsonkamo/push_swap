#include "push_swap.h"
#include <stdio.h>


// この関数は提出の時は消！（debug 用）
void    check_stack(t_data *data)
{
    t_stack *tmp;
    int i = 0;

    if (data == NULL)
        return ;
    tmp = data->a;
    printf("stack a\n");
    while(tmp)
    {
        printf("[%d] %d\n", i++, tmp->origin_num);
        tmp = tmp->next;
    }
    i = 0;
    tmp = data->b;
    printf("stack b\n");
    while(tmp)
    {
        printf("[%d] %d\n", i++, tmp->origin_num);
        tmp = tmp->next;
    }
}

