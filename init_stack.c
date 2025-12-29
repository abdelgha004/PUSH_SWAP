/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 15:52:18 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/29 08:30:58 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*handle_error(char **split_args, int argc, int i)
{
	write(2, "Error\n", 6);
	if (argc == 2)
		free_all(split_args, i);
	return (NULL);
}

int	check_duplicate(t_list *stack, int num)
{   
	while (stack)
	{
		if (stack->content == num)
			return (1);
		stack = stack->next;
	}
	return (0);
}

int	is_valid_number(char *str)
{
	long	num;
	int		i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!ft_isdigit(str[i]))
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	num = ft_atoi(str);
	if (num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

static int	add_number_to_stack(t_list **stack_a, char *str)
{
	int		num;
	t_list	*node;

	if (!is_valid_number(str))
		return (0);
	num = ft_atoi(str);
	if (*stack_a && check_duplicate(*stack_a, num))
		return (0);
	node = ft_lstnew(num);
	if (!node)
	{
		ft_lstclear(stack_a);
		return (0);
	}
	ft_lstadd_back(stack_a, node);
	return (1);
}

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
