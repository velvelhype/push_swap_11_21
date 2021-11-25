#include "push_swap.h"

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

void    implant(t_list *pushing_list, t_list *dst)
{
    pushing_list->next =dst->next;
    pushing_list->prev =dst;
    (pushing_list->next)->prev = pushing_list;
    dst->next = pushing_list;
}

void    push(t_list* src, t_list* dst)
{
    t_list  *pushing_list;
    pushing_list = cut_out_list(src->next);
    implant(pushing_list, dst);

    if (dst->is_dummy == TRUE_A)
        write(1,"pa\n",3);
    else if (dst->is_dummy == TRUE_B)
        write(1,"pb\n",3);
}

void    rotate(t_list *head)
{
    t_list *cut = cut_out_list(head->next);

    implant(cut, head->prev);

    if (head->is_dummy == TRUE_A)
        write(1,"ra\n",3);
    else if (head->is_dummy == TRUE_B)
        write(1,"rb\n",3);
}

void    r_rotate(t_list *head)
{
    t_list *cut = cut_out_list(head->prev);

    implant(cut, head);

    if (head->is_dummy == TRUE_A)
        write(1,"rra\n",4);
    else if (head->is_dummy == TRUE_B)
        write(1,"rrb\n",4);
}