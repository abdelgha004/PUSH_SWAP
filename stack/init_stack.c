/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:52:18 by aakourya          #+#    #+#             */
/*   Updated: 2026/01/04 12:10:48 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_stack(int argc, char **argv)
{
	char	**numbers;
	t_list	*stack_a;
	int		i;
	int		j;

	stack_a = NULL;
	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (!numbers)
			return (ft_lstclear(&stack_a), NULL);
		j = 0;
		while (numbers[j])
		{
			if (!add_number_to_stack(&stack_a, numbers[j]))
				return (handle_error(numbers, -1), ft_lstclear(&stack_a), NULL);
			j++;
		}
		free_all(numbers, -1);
		i++;
	}
	return (stack_a);
}
