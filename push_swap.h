#ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

#define FALSE 0
#define TRUE 1
#define TRUE_A 3
#define TRUE_B 4

typedef struct t_list
{
    struct t_list *next;
    struct t_list *prev;
    int value;
    int is_dummy;
} t_list;

t_list*     append();


void    prepare_lists(int argc, char ** argv, t_list *a_head, t_list *b_head);

//controls
void    swap(t_list* head);
void    push(t_list* a_head, t_list* b_head);
void    rotate(t_list *head);

// check_funcs
void    check_stacks(t_list *a_dummy, t_list *b_dummy);
void    check_stack(t_list *a_head);
void    check_stack_r(t_list *a_head);
void    check_link(t_list *a_head);



#endif