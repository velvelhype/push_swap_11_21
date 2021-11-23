#include "push_swap.h"

int    is_sorted(t_list *a)
{
    t_list *cur;
    t_list *nxt;

    cur = a->next;
    nxt = cur->next;
    while(cur->value < nxt->value && cur->is_dummy == FALSE)
    {
        cur = cur->next;
        nxt = nxt->next;
        if (nxt->is_dummy == TRUE)
            return 1;
    }
    return 0;
}

void    two_sort(t_list *dum)
{
    t_list  *one;
    t_list  *two;
    int     save;

    one = dum->next;
    two = one->next;

    if(one->value > two->value)
        swap(dum);
}

void    three_sort(t_list *dum)
{
    t_list  *one;
    t_list  *two;
    t_list  *three;

    one = dum->next;
    two = one->next;
    three = two->next;
    if(one->value < two->value && one->value < three->value)
    {
        if(two->value > three->value)
        {
            swap(dum);
            rotate(dum);
        }
    }
    if(one->value > two->value && one->value > three->value)
    {
        rotate(dum);
        if(two->value > three->value)
            swap(dum);
    }
    if((two->value + three->value)/ 2 == one->value)
    {
        if(one->value > two->value)
            swap(dum);
        else
            r_rotate(dum);
    }
}

t_list* find_min(t_list *list)
{
    t_list *min_list;

    list = list->next;
    min_list = list;
    list = list->next;
    while(list->is_dummy == FALSE)
    {
        if(list->value < min_list->value)
            min_list = list;
        list = list->next;
    }
    return (min_list);
}

int     len_list(t_list*    head)
{
    int count;

    count = 0;
    head = head->next;
    while(head->is_dummy == FALSE)
    {
        count++;
        head = head->next;
    }

    return count;
}

void    push_min(t_list    *a_head, t_list *b_head)
{
    t_list *min_list;

    min_list = find_min(a_head);

    while(1)
    {
        if(a_head->next == min_list)
        {
            push(a_head, b_head);
            break;
        }
        rotate(a_head);
    }
}

void    five_sort(t_list    *a_head, t_list *b_head)
{
    while (len_list(a_head) > 3)
    {
        push_min(a_head, b_head);
    }
    three_sort(a_head);
    while(len_list(b_head) != 0)
    {
        push(b_head, a_head);
    }
    if((a_head->next)->value > ((a_head->next)->next)->value)
        swap(a_head);
    check_stacks(a_head, b_head);
}