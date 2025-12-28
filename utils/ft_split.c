/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aakourya <aakourya@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 09:45:47 by aakourya          #+#    #+#             */
/*   Updated: 2025/12/28 16:59:22 by aakourya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	count_words(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (!str[i])
			break ;
		count++;
		while (str[i] && str[i] != c)
			i++;
	}
	return (count);
}

static int	get_next_word(const char *s, char c, int *start, int *end)
{
	while (s[*start] && s[*start] == c)
		(*start)++;
	if (!s[*start])
		return (0);
	*end = *start;
	while (s[*end] && s[*end] != c)
		(*end)++;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**arr;
	int		start;
	int		end;
	int		i;

	if (!s)
		return (NULL);
	count = count_words(s, c);
	arr = malloc((count + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	start = 0;
	i = 0;
	while (get_next_word(s, c, &start, &end))
	{
		arr[i] = ft_substr(s, start, end - start);
		if (!arr[i])
			return (free_all(arr, i), NULL);
		start = end;
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
