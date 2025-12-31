/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:29:20 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/31 08:36:07 by aakourya         ###   ########.fr       */
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
	first = (*stack_a)->content;
	second = (*stack_a)->next->content;
	third = (*stack_a)->next->next->content;
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

    min = stack->content;
    while (stack)
    {
        if (stack->content < min)
            min = stack->content;
        stack = stack->next;
    }
    return (min);
}

static void	sort_four_five(t_list **stack_a, t_list **stack_b, int size)
{
    while(size > 3){
        if((*stack_a)->content == find_min(*stack_a)){
            push_b(stack_b, stack_a);
            size--;
        }
        else
            rotate_a(stack_a);
    }
    sort_tree(stack_a);
    while(*stack_b){
        push_a(stack_a, stack_b);
    }
}

void	sort_small_stack(t_list **stack_a, t_list **stack_b, int size)
{
	if (size == 2)
	{
		if ((*stack_a)->content > (*stack_a)->next->content)
			swap_a(stack_a);
	}
	else if (size == 3)
		sort_tree(stack_a);
	else if (size <= 5)
		sort_four_five(stack_a, stack_b, size);
	return ;
}
