/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 16:00:33 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/28 16:59:17 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*next_node;

	if (!lst || !*lst)
		return ;
	while (*lst)
	{
		next_node = (*lst)->next;
		free(*lst);
		*lst = next_node;
	}
	*lst = NULL;
}
