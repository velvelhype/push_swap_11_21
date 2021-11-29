#include "push_swap.h"

void    do_command(char *buf, t_list  *a_head, t_list  *b_head)
{
    if(*buf == 's' && *(buf + 1) == 'a')
        swap(a_head);
    if(*buf == 's' && *(buf + 1) == 'b')
        swap(b_head);
    if(*buf == 's' && *(buf + 1) == 's')
        ss(a_head, b_head);
    if(*buf == 'p' && *(buf + 1) == 'a')
        push(b_head, a_head);
    if(*buf == 'p' && *(buf + 1) == 'b')
        push(a_head, b_head);
    if(*buf == 'r' && *(buf + 1) == 'a')
        rotate(a_head);
    if(*buf == 'r' && *(buf + 1) == 'b')
        rotate(a_head);
    if(*buf == 'r' && *(buf + 1) == 'r')
        rr(a_head, b_head);
    if(*buf == 'r' && *(buf + 1) == 'r' && *(buf + 2) == 'a')
        rrr(a_head, b_head);
    if(*buf == 'r' && *(buf + 1) == 'r' && *(buf + 2) == 'b')
        rrr(a_head, b_head);
    if(*buf == 'r' && *(buf + 1) == 'r' && *(buf + 2) == 'r')
        rrr(a_head, b_head);
}

int main(int argc, char **argv)
{
    t_list  *a_head;
    t_list  *a_copy;
    t_list  *b_head;

    //checks
    pre_process(argc, argv);
    //prepare
    a_head = prepare_a_list(argc, argv, a_head);
    a_copy = prepare_a_list(argc, argv, a_head);
    tend_values(argc, a_head, a_copy);
    b_head = prepare_b_list(b_head);

    char buf[10];

    ft_bzero(buf, 10);
    while(read(0, buf, 3))
    {
        do_command(buf, a_head, b_head);
        ft_bzero(buf, 10);
    }

    if(is_sorted(a_head) == TRUE)
        write(1, "OK\n", ft_strlen("OK\n"));
    else
        write(1, "KO\n", ft_strlen("KO\n"));
}