#include "push_swap.h"

void    check_stacks(t_list *a_dummy, t_list *b_dummy)
{
{
    printf("===========================\n");
    printf("a\t\tb\t\n");
    printf("===========================\n");
    a_dummy = a_dummy->next;
    b_dummy = b_dummy->next;
    int a_end = FALSE;
    int b_end = FALSE;
    while(a_dummy->is_dummy == FALSE || b_dummy->is_dummy == FALSE)
    {
        if(a_dummy->is_dummy != FALSE)
            a_end = TRUE;
        if(b_dummy->is_dummy != FALSE)
            b_end = TRUE;
        if(a_end == FALSE)
        {
            printf("%d\t",a_dummy->value);
            printf("\t");
            a_dummy = a_dummy->next;
        }
        else
            printf("\t\t");
        if(b_end == FALSE)
        {
            printf("%d\t",b_dummy->value);
            printf("\n");
            b_dummy = b_dummy->next;
        }
        else
            printf("\n");
    }
    printf("\n");
    // read(1,NULL,1);
}
}

void    check_stack(t_list *head)
{
    write(1,"stack check : ", 14);
    if (head->is_dummy == TRUE_A)
        write(1,"a\n",2);
    else if (head->is_dummy == TRUE_B)
        write(1,"b\n",2);
    head = head->next;
    while(head->is_dummy == FALSE)
    {
        printf("%d\n",head->value);
        head = head->next;
    }
    char buf[10];
    read(1,buf,1);
}

void    check_stack_r(t_list *head)
{
    head = head->prev;
    while(head->is_dummy == FALSE)
    {
        printf("%d\n",head->value);
        head = head->prev;
    }
}

void    check_link(t_list *head)
{
    int c = 100;

    head = head->prev;
    while(c--)
    {
        printf("%d\n",head->value);
        head = head->prev;
    }
}