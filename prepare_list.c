#include "push_swap.h"


t_list*     append()
{
    t_list  *new;
    new = malloc(sizeof(t_list));
    return (new);
}

void    prepare_lists(int argc, char **argv, t_list **a_head, t_list **b_head)
{
    int count;
    t_list *a;

    *a_head = append();
    *b_head = append();

    count = argc;
    *a_head->is_dummy = TRUE_A;
    a = *a_head;
    while(argc-- - 1)
    {
        *a_head->next = malloc(sizeof(t_list));
        (*a_head->next)->prev = *a_head;
        (*a_head->next)->is_dummy = FALSE;
        (*a_head->next)->value = ft_atoi(argv[count - argc]);
        *a_head = *a_head->next;
    }
    *a_head->next = a;
    a->prev = *a_head;

    // b_head->next = b_head;
    // b_head->prev = b_head;
    // b_head->is_dummy = TRUE_B;
}