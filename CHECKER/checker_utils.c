/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 10:57:15 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/09 16:14:35 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	execute_instruction(char *line, t_list **stack_a, t_list **stack_b)
{
	if (!ft_strncmp(line, "sa\n", 3))
		swap_a(stack_a, 0);
	else if (!ft_strncmp(line, "sb\n", 3))
		swap_b(stack_b, 0);
	else if (!ft_strncmp(line, "ss\n", 3))
		swap_a_and_b(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pa\n", 3))
		push_a(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "pb\n", 3))
		push_b(stack_b, stack_a, 0);
	else if (!ft_strncmp(line, "ra\n", 3))
		rotate_a(stack_a, 0);
	else if (!ft_strncmp(line, "rb\n", 3))
		rotate_b(stack_b, 0);
	else if (!ft_strncmp(line, "rr\n", 3))
		rotate_a_and_b(stack_a, stack_b, 0);
	else if (!ft_strncmp(line, "rra\n", 4))
		reverse_rotate_a(stack_a, 0);
	else if (!ft_strncmp(line, "rrb\n", 4))
		reverse_rotate_b(stack_b, 0);
	else if (!ft_strncmp(line, "rrr\n", 4))
		reverse_rotate_a_and_b(stack_a, stack_b, 0);
	else
		return (0);
	return (1);
}
