/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:36:52 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/24 11:00:20 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverse_rotate_stack(t_list **stack){
    t_list *first;
    t_list *last;
    t_list *before_last;
    
    first = *stack;
    before_last = *stack;
    while (before_last->next->next)
        before_last = before_last->next;
    last = before_last->next;
    before_last->next = NULL;
    last->next = first;
    *stack = last;
}

void reverse_rotate_a(t_list **stack_a){
    if(!stack_a || !*stack_a || !(*stack_a)->next)
        return ;
    reverse_rotate_stack(stack_a);
    write(1, "rra\n", 4);
}

void reverse_rotate_b(t_list **stack_b)
{
    if(!stack_b || !*stack_b || !(*stack_b)->next)
        return ;
    reverse_rotate_stack(stack_b);
    write(1,"rrb\n", 4);
}

void reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b){

    int rotate = 0;
    if (stack_a && *stack_a && (*stack_a)->next)
    {
        reverse_rotate_stack(stack_a);
        rotate = 1;
    }
    if(stack_b && *stack_b && (*stack_b)->next)
    {
        reverse_rotate_stack(stack_b);
        rotate = 1;
    }
    if(rotate)
        write(1, "rrr\n", 4);
}