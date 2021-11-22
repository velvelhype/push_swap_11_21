#include "push_swap.h"

int main(int argc, char **argv)
{
    t_list  *a_head; //->0x100
    t_list  *b_head; //->0x110

    printf("%d\n", argc);
    //check arg
    //prepare list
    // a_head = append();
    // b_head = append();
    prepare_lists(argc, argv, &a_head, &b_head);
    //clean up data
    //sort
    push(a_head, b_head);
    push(a_head, b_head); 
    push(a_head, b_head);
    // push(a_head, b_head);
    //after sort
    check_stacks(a_head, b_head);
    rotate(a_head);
    check_stacks(a_head, b_head);
    rotate(a_head);
    // check_stacks(a_head, b_head);
    // rotate(a_head);
    // check_stacks(a_head, b_head);
    // rotate(a_head);
    // check_stacks(a_head, b_head);
    // rotate(a_head);
    // check_stacks(a_head, b_head);
    // rotate(a_head);
    // check_stacks(a_head, b_head);

}