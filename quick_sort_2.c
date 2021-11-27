#include "push_swap.h"

void    init(t_list *a_head, t_list *b_head)
{
    int pivot;
    int len;
    int export_vol;
    int ruminant_count;

    ruminant_count = 0;
    pivot = (find_min(a_head))->value + len_list(a_head) / 2;
    // printf("pivot is %d\n", pivot);
    len = len_list(a_head);
    export_vol = len / 2;
    while(len--)
    {
        if((a_head->next)->value < pivot)
        {
            push(a_head, b_head);
        }
        else
        {
            ruminant_count++;
            rotate(a_head);
        }
    }
    process_b(a_head, b_head);
    ruminant(ruminant_count, a_head, b_head);
}

void    clean_up(t_list *a_head, t_list *b_head)
{
    while(len_list(b_head) != 0)
    {
        push_min(b_head, a_head);
        rotate(a_head);
    }
}

int     cut_half_b(t_list *a_head, t_list *b_head)
{
    int pivot;
    int len;
    int ruminant_count;

    pivot = (find_min(b_head))->value + len_list(b_head) / 2;
    len = len_list(b_head);
    ruminant_count = 0;
    while(len--)
    {
        if((b_head->next)->value > pivot)
        {
            push(b_head, a_head);
            ruminant_count++;
        }
        else
            rotate(b_head);
    }
    // printf("cut done\n");
    // check_stacks(a_head, b_head);
    return (ruminant_count);
}

void    ruminant(int ruminant_count, t_list *a_head, t_list *b_head)
{
    while(ruminant_count--)
        push(a_head, b_head);
    // printf("ruminanted\n");
    // check_stacks(a_head, b_head);
    process_b(a_head, b_head);
}

void    process_b(t_list *a_head, t_list *b_head)
{
    int ruminant_count;

    if(len_list(b_head) < CLEANING_VOL)
        clean_up(a_head, b_head);
    else
    {
        ruminant_count = cut_half_b(a_head, b_head);
        process_b(a_head, b_head);
        ruminant(ruminant_count, a_head, b_head);
    }
}

void    quick_sort_2(t_list *a_head, t_list *b_head)
{
    init(a_head, b_head);
}
