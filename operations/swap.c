/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:36:39 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/23 11:55:02 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int swap_stack(t_list *stack){
    t_list *node;
    t_list *tmp;
    int len;
    
    node = stack;
    len = ft_lstsize(node);
    node = stack;
    if(len > 2){
        while (node->next->next->next)
            node = node->next;
        tmp = node->next;
        node->next = node->next->next;
        node->next->next = tmp;
        node->next->next->next = NULL;
    }else if(len == 2)
    {
        tmp = node;
        node = node->next;
        node->next = tmp;
        node->next->next = NULL;
    }
    return (len);
}

void swap_a(t_list *stack_a){
    int len;
    len = swap_stack(stack_a);
    if(len >= 2)
        write(1, "sa, ", 4);
}

void swap_b(t_list *stack_b){
    int len;
    len = swap_stack(stack_b);
    if(len >= 2)
        write(1, "sb, ", 4);
}

void swap_a_and_b(t_list *stack_a, t_list *stack_b){
    int len_a;
    int len_b;
    len_a = swap_stack(stack_a);
    len_b = swap_stack(stack_b);
    if(len_a >= 2 && len_b >= 2)
        write(1, "ss, ", 4);
}
