#include "push_swap.h"

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
    //checks
    pre_process(argc, argv);
    //prepare
    a_head = prepare_a_list(argc, argv, a_head);
    a_copy = prepare_a_list(argc, argv, a_head);
    tend_values(argc, a_head, a_copy);
    b_head = prepare_b_list(b_head);
    quick_sort_2(a_head, b_head);
    // printf("sorted? : %d", is_sorted(a_head));
    //free
    a_head = a_head ->prev;
    while(a_head->is_dummy == FALSE)
    {
        a_head = a_head->prev;
        free(a_head->next);
    }
    free(a_head);
    free(b_head);
    return 0;
}