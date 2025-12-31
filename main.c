/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/29 08:31:20 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/31 09:08:30 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

// to remove after testing
void print_stack(t_list *stack)
{
    while (stack)
    {
        printf("%d ", stack->content);
        stack = stack->next;
    }
    printf("\n");
}

int main(int argc, char **argv){
    t_list *stack_a;
    t_list *stack_b;
    int size;
    if(argc < 2)
        return (0);
    stack_a = create_stack(argc, argv);
    if (!stack_a)
        return (1); 
    stack_b = NULL;
    size = ft_lstsize(stack_a);
    if(size > 1)
        sort_stack(&stack_a, &stack_b, size);
    
    //to
    print_stack(stack_a);
    ft_lstclear(&stack_a);

    return (0);
}