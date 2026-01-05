    /* ************************************************************************** */
    /*                                                                            */
    /*                                                        :::      ::::::::   */
    /*   sort.c                                             :+:      :+:    :+:   */
    /*                                                    +:+ +:+         +:+     */
    /*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
    /*                                                +#+#+#+#+#+   +#+           */
    /*   Created: 2025/12/29 09:23:57 by aakourya          #+#    #+#             */
    /*   Updated: 2025/12/30 09:18:34 by aakourya         ###   ########.fr       */
    /*                                                                            */
    /* ************************************************************************** */

    #include "../push_swap.h"

    void sort_stack(t_list **stack_a, t_list **stack_b, int size)
    {   
        if(is_sorted(*stack_a))
            return;
        if(size <= 5){
            sort_small_stack(stack_a, stack_b, size);
        }
        else if(size <= 100){
             sort_medium_stack(stack_a, stack_b, size);
        }/*else{
            sort_large_stack(stack_a, stack_b, size);
        }
        *stack_b = NULL;
        return;*/
    }
