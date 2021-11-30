#include "push_swap.h"

void    free_lists(t_list* a_head, t_list* b_head)
{
    a_head = a_head ->prev;
    while(a_head->is_dummy == FALSE)
    {
        a_head = a_head->prev;
        free(a_head->next);
    }
    free(a_head);
    free(b_head);
}

int main(int argc, char **argv)
{
    t_list  *a_head;
    t_list  *a_copy;
    t_list  *b_head;

    if(argc == 1)
        {
            printf("you damn shit!!!\n");
            exit(1);
        }
    //arg_checks
    pre_process(argc, argv);
    //prepare
    a_head = prepare_a_list(argc, argv, a_head);
    a_copy = prepare_a_list(argc, argv, a_head);
    tend_values(argc, a_head, a_copy);
    b_head = prepare_b_list(b_head);
    // if sorted
    if(is_sorted(a_head) == TRUE)
    {
        free_lists(a_head, b_head);
        exit(1);
    }
    // 3 < 5 < INT_MAX
    if (len_list(a_head) == 2)
        two_sort(a_head);
    else if (len_list(a_head) <= 3)
        three_sort(a_head);
    else if (len_list(a_head) <= 5)
        five_sort(a_head, b_head);
    else
        quick_sort_2(a_head, b_head);

    //check
    // check_stack(a_head);

    //free
    free_lists(a_head, b_head);
    return 0;
}