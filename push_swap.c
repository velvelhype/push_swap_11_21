#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *a_head; //->0x100
    t_list  *a_copy; //->0x100
    t_list  *b_head; //->0x110

    if(argc == 1)
        {
            printf("you damn shit!!!\n");
            exit(1);
        }
    //=====check arg
    //=====prepare list
    a_head = prepare_a_list(argc, argv, a_head);
    a_copy = prepare_a_list(argc, argv, a_head);
    tend_values(argc, a_head, a_copy);
    b_head = prepare_b_list(b_head);
    // printf("list prepared\n");
    // check_stack(a_head);
    // =====sorts
    // printf("quick_sort\n");
    quick_sort(a_head, b_head);
    // if(argc - 1 > 5)
        // quick_sort(a_head, b_head);
    //five_sort
    // if(argc - 1 > 3 && argc - 1 < 6)
    //     five_sort(a_head, b_head);
    //three_sort
    //two_sort

    //conclude
    if(is_sorted(a_head) == TRUE)
        printf("SORTED\n");
    else
        printf("FAIL\n");
    // check_stack(a_head);
    //free
    free(b_head);
    return 0;
}