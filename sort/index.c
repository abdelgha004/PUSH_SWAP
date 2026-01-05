/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/01 09:30:01 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/01 10:09:18 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void assign_index(t_list *stack)
{    
    t_list *current;
    t_list *tmp;
    int index;

    current = stack;
    while (current)
    {
        index = 0;
        tmp = stack;
        while (tmp)
        {
            if(tmp->content < current->content)
                index++;
            tmp = tmp->next;
        }

        current->index = index;
        current = current->next;
    }
}
