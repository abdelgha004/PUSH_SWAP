/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 09:36:39 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/09 16:13:32 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap_stack(t_list **stack)
{
	t_list	*first;
	t_list	*second;

	first = *stack;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	swap_a(t_list **stack_a, int print)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	swap_stack(stack_a);
	if (print)
		write(1, "sa\n", 3);
}

void	swap_b(t_list **stack_b, int print)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	swap_stack(stack_b);
	if (print)
		write(1, "sb\n", 3);
}

void	swap_a_and_b(t_list **stack_a, t_list **stack_b, int print)
{
	int	swapped;

	swapped = 0;
	if (stack_a && *stack_a && (*stack_a)->next)
	{
		swap_stack(stack_a);
		swapped = 1;
	}
	if (stack_b && *stack_b && (*stack_b)->next)
	{
		swap_stack(stack_b);
		swapped = 1;
	}
	if (swapped && print)
		write(1, "ss\n", 3);
}
