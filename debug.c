#include "push_swap.h"

#ifdef DEBUG
void    debug_print_stack(const char *name, t_node *s)
{
    ft_printf("=== %s ===\n", name);
    while (s != NULL)
    {
        /* Ajusta estos campos a tu struct: value / index */
        ft_printf("val=%d  idx=%d\n", s->value, s->i);
        s = s->next;
    }
    ft_printf("-----------\n");
}

void    debug_print_stacks(t_node *a, t_node *b)
{
    t_node  *pa;
    t_node  *pb;

    pa = a;
    pb = b;
    ft_printf("====   A           B   ====\n");
    while (pa != NULL || pb != NULL)
    {
        if (pa != NULL && pb != NULL)
            ft_printf("      %d(%d)   %d(%d)\n",
                pa->value, pa->i, pb->value, pb->i);
        else if (pa != NULL)
            ft_printf("      %d(%d)\n", pa->value, pa->i);
        else
            ft_printf("              %d(%d)\n", pb->value, pb->i);
        if (pa != NULL)
            pa = pa->next;
        if (pb != NULL)
            pb = pb->next;
    }
    ft_printf("===========================\n");
}
#endif
