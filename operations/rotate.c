/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:36:34 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/09 16:12:32 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_stack(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	last = *stack;
	while (last->next)
		last = last->next;
	*stack = first->next;
	first->next = NULL;
	last->next = first;
}

void	rotate_a(t_list **stack_a, int print)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	rotate_stack(stack_a);
	if (print)
		write(1, "ra\n", 3);
}

void	rotate_b(t_list **stack_b, int print)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	rotate_stack(stack_b);
	if (print)
		write(1, "rb\n", 3);
}

void	rotate_a_and_b(t_list **stack_a, t_list **stack_b, int print)
{
	int	rotate;

	rotate = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		rotate_stack(stack_a);
		rotate = 1;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		rotate_stack(stack_b);
		rotate = 1;
	}
	if (rotate && print)
		write(1, "rr\n", 3);
}
