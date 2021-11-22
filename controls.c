#include "push_swap.h"
// swap
// push
// rotate
// r_rotate

void    swap(t_list* head)
{
    int save;

    save = (head->next)->value;
    (head->next)->value = ((head->next)->next)->value;
    ((head->next)->next)->value = save;

    if (head->is_dummy == TRUE_A)
        write(1,"sa\n",3);
    else if (head->is_dummy == TRUE_B)
        write(1,"sb\n",3);
}

t_list*    cut_out_list(t_list *cut)
{
    (cut->next)->prev = cut->prev; 
    (cut->prev)->next = cut->next;

    cut->next = NULL;
    cut->prev =  NULL;

    return  cut;
}

void    implant(t_list *pushing_list, t_list *b_head)
{
    // b_head pushing_list next
    pushing_list->next = b_head->next;
    pushing_list->prev = b_head;
    (pushing_list->next)->prev = pushing_list;
    b_head->next = pushing_list;
}


void    push(t_list* src, t_list* dst)
{
    t_list  *pushing_list;
    //cut out a hole to a
    pushing_list = cut_out_list(src->next);
    //implant list to b
    implant(pushing_list, dst);

    if (dst->is_dummy == TRUE_A)
        write(1,"pa\n",3);
    else if (dst->is_dummy == TRUE_B)
        write(1,"pb\n",3);
}

void    rotate(t_list *head)
{
    int save;
    int temp;
    t_list *cur_list;

    save = (head->next)->value;
    cur_list = head->prev;
    while(cur_list->is_dummy == FALSE)
    {
        temp = cur_list->value;
        cur_list->value = save;
        save = temp;
        cur_list = cur_list->prev;
    }
}