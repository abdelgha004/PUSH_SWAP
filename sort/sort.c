/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 09:23:57 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/29 10:07:27 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int  is_sorted(t_list *stack)
{
    while(stack->next){
        if(stack->content > stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}

void sort_stack(t_list **stack_a, t_list **stack_b, int size)
{   
    if(is_sorted(*stack_a))
        return;
    if(size == 2){
        if((*stack_a)->content > (*stack_a)->next->content)
            swap_a(stack_a);
    }
    *stack_b = NULL;
    /* else if(size <= 5){
        // Implement sorting logic for 3 to 5 elements
    } else if(size <= 100){
        // Implement sorting logic for 6 to 100 elements
    } else {
        // Implement sorting logic for more than 100 elements       
    }
    */

    return;
}