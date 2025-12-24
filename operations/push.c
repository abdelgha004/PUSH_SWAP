/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:36:28 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/24 10:40:19 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push_a(t_list **stack_a, t_list **stack_b)
{
    t_list *first;

    if (!stack_b || !*stack_b)
        return;
    first = *stack_b;
    *stack_b = first->next;
    first->next = *stack_a;
    *stack_a = first;

    write(1, "pa\n", 3);
}

void push_b(t_list **stack_b, t_list **stack_a)
{
    t_list *first;

    if (!stack_a || !*stack_a)
        return;
    first = *stack_a;
    *stack_a = first->next;
    first->next = *stack_b;
    *stack_b = first;

    write(1, "pb\n", 3);
}