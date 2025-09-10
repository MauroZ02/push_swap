/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzangaro <mzangaro@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 20:03:08 by mzangaro          #+#    #+#             */
/*   Updated: 2025/09/10 22:18:29 by mzangaro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int collect_tokens(int argc, char **argv, char ***out_tokens, int *out_count)
{
	int	i;

	i = 0;

	ft_split(argv[1], ' ');

}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	return (0);
}

/* Helper to visualise in Terminal */
/*
void print_list(const char *label, t_node *head)
{
    t_node *p = head;

    printf("%s", label);
    while (p)
    {
        printf("%d", p->value);
        if (p->next) printf(" -> ");
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
	t_node *a = NULL;
	t_node *b = NULL;

	t_node *n1 = new_node(10);
	t_node *n2 = new_node(20);
	t_node *n3 = new_node(30);
	t_node *n4 = new_node(40);
	t_node *n5 = new_node(100);
	t_node *n6 = new_node(200);
	t_node *n7 = new_node(300);
	t_node *n8 = new_node(400);
	a = n1;
	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = NULL;

	b = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = NULL;

	print_list("A before: ", a);
	print_list("B before: ", b);

	// pa(&a, &b);
	// pb(&a, &b);
	// sa(&a);
	// sb(&b);
	// ss(&a, &b);
	// ra(&a);
	// rb(&b);
	// rr(&a, &b);
	// rra(&a);
	// rrb(&b);
	 rrr(&a, &b);

	print_list("A after : ", a);
	print_list("B after : ", b);

	free_stack(&a);
	free_stack(&b);

	return 0;
} */
