/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/20 06:21:29 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/29 09:40:38 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

/* Struct for linked list nodes */
typedef struct s_list
{
	int				content;
	struct s_list	*next;
}	    t_list;

/* Stack operations */
void	push_a(t_list **stack_a, t_list **stack_b);
void	push_b(t_list **stack_b, t_list **stack_a);
void	swap_a(t_list **stack_a);
void	swap_b(t_list **stack_b);
void	swap_a_and_b(t_list **stack_a, t_list **stack_b);
void	rotate_a(t_list **stack_a);
void	rotate_b(t_list **stack_b);
void	rotate_a_and_b(t_list **stack_a, t_list **stack_b);
void	reverse_rotate_a(t_list **stack_a);
void	reverse_rotate_b(t_list **stack_b);
void	reverse_rotate_a_and_b(t_list **stack_a, t_list **stack_b);

/* LIBFT */
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlen(const char *s);
int		ft_atoi(const char *nptr);
void	free_all(char **arr, int i);
int		ft_isdigit(int c);

/* LINKED LIST */
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(int content);
void	ft_lstclear(t_list **lst);
int ft_lstsize(t_list *lst);

/* SORTING */
void sort_stack(t_list **stack_a, t_list **stack_b, int size);

/* STACK INIT */
t_list	*create_stack(int argc, char **argv);

#endif