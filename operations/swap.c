/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:36:39 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/24 10:29:45 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void swap_stack(t_list **stack)
{
    t_list *first;
    t_list *second;

    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

void swap_a(t_list **stack_a)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    swap_stack(stack_a);
    write(1, "sa\n", 3);
}

void swap_b(t_list **stack_b)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    swap_stack(stack_b);
    write(1, "sb\n", 3);
}

void swap_a_and_b(t_list **stack_a, t_list **stack_b)
{
    int swapped = 0;
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        swap_stack(stack_a);
        swapped = 1;
    }
    if (stack_b && *stack_b && (*stack_b)->next)
    {
        swap_stack(stack_b);
        swapped = 1;
    }
    if (swapped)
        write(1, "ss\n", 3);
}
