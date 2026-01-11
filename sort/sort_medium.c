/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 15:59:48 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/09 16:45:31 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_medium_stack(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk_size;
	int	chunk_limit;
	int	pushed;

	chunk_size = size / 5;
	chunk_limit = chunk_size;
	pushed = 0;
	while (*stack_a)
	{
		if ((*stack_a)->index < chunk_limit)
		{
			push_b(stack_b, stack_a, 1);
			pushed++;
			if ((*stack_b)->index < (chunk_limit - (chunk_size / 2)))
				rotate_b(stack_b, 1);
		}
		else if (get_pos_in_chunk(*stack_a, chunk_limit) >= (size / 2))
			reverse_rotate_a(stack_a, 1);
		else
			rotate_a(stack_a, 1);
		if (pushed == chunk_limit && chunk_limit < size)
			chunk_limit += chunk_size;
	}
	push_back_to_a(stack_a, stack_b, size);
}
