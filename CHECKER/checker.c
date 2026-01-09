/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/09 06:31:57 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/09 11:28:03 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include "get_next_line/get_next_line.h"

static int	run_checker(t_list **stack_a, t_list **stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_instruction(line, stack_a, stack_b))
		{
			write(2, "Error\n", 6);
			free(line);
			return (0);
		}
		free(line);
		line = get_next_line(0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		result;

	if (argc < 2)
		return (0);
	stack_a = create_stack(argc, argv);
	if (!stack_a)
		return (1);
	stack_b = NULL;
	result = run_checker(&stack_a, &stack_b);
	if (!result)
	{
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
		return (1);
	}
	if (is_sorted(stack_a) && !stack_b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
