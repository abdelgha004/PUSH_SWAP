/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/30 09:12:04 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/30 10:26:18 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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

int	add_number_to_stack(t_list **stack_a, char *str)
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

int  is_sorted(t_list *stack)
{
    while(stack->next){
        if(stack->content > stack->next->content)
            return (0);
        stack = stack->next;
    }
    return (1);
}
