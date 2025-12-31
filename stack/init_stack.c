/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:52:18 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/30 09:15:53 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*create_stack(int argc, char **argv)
{
	char	**split_args;
	t_list	*stack_a;
	int		i;

	if (argc == 2)
	{
		split_args = ft_split(argv[1], ' ');
		if (!split_args)
			return (NULL);
	}
	else if (argc > 2)
		split_args = &argv[1];
	else
		return (NULL);
	stack_a = NULL;
	i = 0;
	while (split_args[i])
	{
		if (!add_number_to_stack(&stack_a, split_args[i]))
			return (handle_error(split_args, argc, i));
		i++;
	}
	if (argc == 2)
		free_all(split_args, i);
	return (stack_a);
}
