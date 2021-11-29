#include "push_swap.h"

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
        write(1, buf, 3);
        ft_bzero(buf, 10);
    }

    if(is_sorted(a_head) == TRUE)
        write(1, "OK\n", ft_strlen("OK\n"));
    else
        write(1, "KO\n", ft_strlen("KO\n"));
}