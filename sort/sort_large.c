/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_large.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/08 08:27:22 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/09 16:18:00 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_large_stack(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk_limit;
	int	i;

	i = 0;
	chunk_limit = 30;
	while (*stack_a)
	{
		if ((*stack_a)->index <= i)
		{
			push_b(stack_b, stack_a, 1);
			i++;
		}
		else if ((*stack_a)->index < i + chunk_limit)
		{
			push_b(stack_b, stack_a, 1);
			rotate_b(stack_b, 1);
			i++;
		}
		else
			rotate_a(stack_a, 1);
	}
	push_back_to_a(stack_a, stack_b, size);
}
