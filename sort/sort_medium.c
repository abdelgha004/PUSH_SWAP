/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:59:48 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/08 06:51:10 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_medium_stack(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk_size;
	int	chunk_limit;
	int	position;
	int	i;

 	chunk_size = size / 4 + 1;
 	chunk_limit = chunk_size;
 	i = 0;
 	while (*stack_a && i < size)
 	{
 		position = get_pos_in_chunk(*stack_a, chunk_limit);
 		if ((*stack_a)->index < chunk_limit)
 		{
 			push_b(stack_b, stack_a);
 			i++;
            if(i < size && (*stack_b)->index < (chunk_limit - (chunk_size / 2)))
                rotate_b(stack_b);
 		}
 		else if (position >= (size / 2))
 			reverse_rotate_a(stack_a);
 		else
 			rotate_a(stack_a);
 		if (i == chunk_limit && chunk_limit < size)
 			chunk_limit += chunk_size;
 	}
 	push_back_to_a(stack_a, stack_b, size);
}
