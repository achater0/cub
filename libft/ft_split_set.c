/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_set.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:13:38 by mstaali           #+#    #+#             */
/*   Updated: 2024/09/17 14:14:08 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_set_char(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_countsubstr_set(const char *s, const char *set)
{
	int		found;
	int		count;

	found = 0;
	count = 0;
	while (*s)
	{
		if (!is_set_char(set, *s))
		{
			if (!found)
			{
				count++;
				found = 1;
			}
		}
		else
			found = 0;
		s++;
	}
	return (count);
}

static char	**ft_free_array(char **array)
{
	size_t	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

char	**ft_split_set(char const *s, const char *set)
{
	char	**array;
	size_t	arr_i;
	size_t	start;
	size_t	i;

	if (!s)
		return (NULL);
	array = (char **)malloc((ft_countsubstr_set(s, set) + 1) * sizeof(char *));
	if (!array)
		return (NULL);
	i = 0;
	arr_i = 0;
	while (s[i])
	{
		if (s[i] && is_set_char(set, s[i]) && ++i)
			continue ;
		start = i;
		while (s[i] && !is_set_char(set, s[i]))
			i++;
		array[arr_i++] = ft_substr(s, start, i - start);
		if (!array[arr_i - 1])
			return (ft_free_array(array));
	}
	array[arr_i] = NULL;
	return (array);
}
