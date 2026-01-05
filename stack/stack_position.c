/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_position.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/04 15:26:04 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/04 15:38:49 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int get_position(t_list *stack, int index)
{
    int position;
    
    position = 0;
    while(stack)
    {
        if(stack->index == index)
            return (position);
        position++;
        stack = stack->next;
    }
    return (-1);
}