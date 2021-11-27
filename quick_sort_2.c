#include "push_swap.h"

void    init(t_list *a_head, t_list *b_head)
{
    int pivot;
    int len;
    int ruminant_count;
    int shipment;

    ruminant_count = 0;
    pivot = (find_min(a_head))->value + len_list(a_head) / 2;
    len = len_list(a_head);
    shipment = len / 2;
    ruminant_count = len - shipment;
    while(shipment)
    {
        if((a_head->next)->value < pivot)
        {
            shipment--;
            push(a_head, b_head);
        }
        else
            rotate(a_head);
    }
    // printf("init done %d %d\n", len_list(a_head), len_list(b_head));
    // check_stacks(a_head, b_head);
    process_b(a_head, b_head);
    ruminant(ruminant_count, a_head, b_head);
}

void     cut_half(t_list *a_head, t_list *b_head)
{
    int pivot;
    int len;
    int ruminant_count;
    int shipment;

    ruminant_count = 0;
    pivot = (find_min(b_head))->value + len_list(b_head) / 2;
    len = len_list(b_head);
    shipment = len / 2;
    while(len--)
    {
        if((b_head->next)->value > pivot)
        {
            push(b_head, a_head);
            ruminant_count++;
        }
        else
            rotate(b_head);
        if(shipment == ruminant_count)
            break;
    }
    // printf("cut done\n");
    // check_stacks(a_head, b_head);
    process_b(a_head, b_head);
    ruminant(ruminant_count, a_head, b_head);
}

void    ruminant(int ruminant_count, t_list *a_head, t_list *b_head)
{
    while(ruminant_count--)
        push(a_head, b_head);
    // printf("ruminanted\n");
    // check_stacks(a_head, b_head);
    process_b(a_head, b_head);
}

void    clean_up(t_list *a_head, t_list *b_head)
{
    while(len_list(b_head) != 0)
    {
        push_min(b_head, a_head);
        rotate(a_head);
    }
}

void    process_b(t_list *a_head, t_list *b_head)
{
    if(len_list(b_head) < CLEANING_VOL)
        clean_up(a_head, b_head);
    else
        cut_half(a_head, b_head);
}

void    quick_sort_2(t_list *a_head, t_list *b_head)
{
    init(a_head, b_head);
}
