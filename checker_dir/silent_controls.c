#include "push_swap.h"

void    swap(t_list* head)
{
    int save;

    save = (head->next)->value;
    (head->next)->value = ((head->next)->next)->value;
    ((head->next)->next)->value = save;
}

void    ss(t_list *a_head, t_list *b_head)
{
	int save_a;
	int save_b;

    save_a = (a_head->next)->value;
    (a_head->next)->value = ((a_head->next)->next)->value;
    ((a_head->next)->next)->value = save_a;
    save_b = (b_head->next)->value;
    (b_head->next)->value = ((b_head->next)->next)->value;
    ((b_head->next)->next)->value = save_b;
}

t_list*    cut_out_list(t_list *cut)
{
    (cut->next)->prev = cut->prev;
    (cut->prev)->next = cut->next;
	cut->next = NULL;
    cut->prev = NULL;

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
}

void    rotate(t_list *head)
{
    t_list *cut;
    
    cut = cut_out_list(head->next);
    implant(cut, head->prev);
}

void    rr(t_list *a_head, t_list *b_head)
{
    t_list *cut_a;
    t_list *cut_b;
    
    cut_a = cut_out_list(a_head->next);
    implant(cut_a, a_head->prev);
    cut_b = cut_out_list(b_head->next);
    implant(cut_b, b_head->prev);
}

void    r_rotate(t_list *head)
{
    t_list *cut = cut_out_list(head->prev);

    implant(cut, head);
}

void    rrr(t_list *a_head, t_list *b_head)
{
    t_list *cut_a;
    t_list *cut_b;

    cut_a = cut_out_list(a_head->prev);
    implant(cut_a, a_head);
    cut_b = cut_out_list(b_head->prev);
    implant(cut_b, b_head);
}