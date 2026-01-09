/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_helpers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/06 18:15:01 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/09 16:19:45 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_pos_in_chunk(t_list *stack, int chunk_limit)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack->index < chunk_limit)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (-1);
}

int	get_position(t_list *stack, int index)
{
	int	position;

	position = 0;
	while (stack)
	{
		if (stack->index == index)
			return (position);
		position++;
		stack = stack->next;
	}
	return (-1);
}

void	push_back_to_a(t_list **stack_a, t_list **stack_b, int size)
{
	int	position;
	int	max_index;

	while (size > 0)
	{
		max_index = size - 1;
		position = get_position(*stack_b, max_index);
		if ((*stack_b)->index == max_index)
		{
			push_a(stack_a, stack_b, 1);
			size--;
		}
		else if ((*stack_b)->next && (*stack_b)->next->index == max_index)
			swap_b(stack_b, 1);
		else if (position <= (size / 2))
			rotate_b(stack_b, 1);
		else
			reverse_rotate_b(stack_b, 1);
	}
}

void	assign_index(t_list *stack)
{
	t_list	*current;
	t_list	*tmp;
	int		index;

	current = stack;
	while (current)
	{
		index = 0;
		tmp = stack;
		while (tmp)
		{
			if (tmp->content < current->content)
				index++;
			tmp = tmp->next;
		}
		current->index = index;
		current = current->next;
	}
}
