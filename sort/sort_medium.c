/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:29:23 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/05 08:31:46 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int find_min(t_list *stack)
{
    int min;

    min = stack->index;
    while (stack)
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return (min);
}

void sort_medium_stack(t_list **stack_a, t_list **stack_b, int size)
{
    int position;
    int mid_index;
    
    if(is_sorted(*stack_a))
            return;
    while(size > 5)
    {
        mid_index = find_min(*stack_a);
        position = get_position(*stack_a, mid_index);
        if((*stack_a)->index == mid_index){
            push_b(stack_b, stack_a);
            size--;
        }else if(position <= size / 2){
            rotate_a(stack_a);
        }else{
            reverse_rotate_a(stack_a);
        }
    }
    sort_small_stack(stack_a, stack_b, ft_lstsize(*stack_a));
    while(*stack_b)
        push_a(stack_a, stack_b);
}