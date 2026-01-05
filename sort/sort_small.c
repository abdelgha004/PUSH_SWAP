/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:29:20 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/05 08:11:58 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_tree(t_list **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (is_sorted(*stack_a))
		return ;
	first = (*stack_a)->index;
	second = (*stack_a)->next->index;
	third = (*stack_a)->next->next->index;
	if (first > second && second < third && first < third)
		swap_a(stack_a);
	else if (first > second && second < third && first > third)
		rotate_a(stack_a);
	else if (first < second && second > third && first > third)
		reverse_rotate_a(stack_a);
	else if (first < second && second > third && first < third)
	{
		swap_a(stack_a);
		rotate_a(stack_a);
	}
	else if (first > second && second > third && first > third)
	{
		swap_a(stack_a);
		reverse_rotate_a(stack_a);
	}
}

static int find_min(t_list *stack)
{
    int min;

    min = stack->index;
    while (stack)
    {
        if (stack->index < min)
            min = stack->index;
        stack = stack->next;
    }
    return (min);
}

static void	sort_four_five(t_list **stack_a, t_list **stack_b, int size)
{
    int position;
    int min_index;
    while (size > 3)
    {
        min_index = find_min(*stack_a);
        position = get_position(*stack_a, min_index);
        if ((*stack_a)->index == min_index)
        {
            push_b(stack_b, stack_a);
            size--;
        }else if(position  >= (size / 2))
            reverse_rotate_a(stack_a);
        else
            rotate_a(stack_a);
    }
    sort_tree(stack_a);
    while(*stack_b)
        push_a(stack_a, stack_b);
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->index > (*stack_a)->next->index)
			swap_a(stack_a);
	}
	else if (size == 3)
		sort_tree(stack_a);
	else if (size <= 5)
		sort_four_five(stack_a, stack_b, size);
	return ;
}
