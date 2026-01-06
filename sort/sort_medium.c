/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_medium.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:29:23 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/06 11:14:41 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push_back_to_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	position;
	int	max_index;

	while (size > 0)
	{
		max_index = size - 1;
		position = get_position(*stack_b, max_index);
		if ((*stack_b)->index == max_index)
		{
			push_a(stack_a, stack_b);
			size--;
		}
		else if (position >= (size / 2))
			reverse_rotate_b(stack_b);
		else
			rotate_b(stack_b);
	}
}

void	sort_medium_stack(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk_size;
	int	chunk_limit;
	int	position;
	int	i;

	chunk_size = size / 6;
	chunk_limit = chunk_size;
	i = 0;
	while (*stack_a && i < size)
	{
		position = get_position(*stack_a, i);
		if ((*stack_a)->index < chunk_limit)
		{
			push_b(stack_b, stack_a);
			i++;
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
