/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/19 17:04:36 by mstaali           #+#    #+#             */
/*   Updated: 2024/10/19 17:05:32 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

size_t	ft_gnl_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	if (c == '\0')
		return ((char *)&s[ft_gnl_strlen(s)]);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_gnl_strjoin(char *stored, char *buffer)
{
	size_t	i;
	size_t	j;
	char	*str;

	if (!stored)
	{
		stored = (char *)malloc(1);
		stored[0] = '\0';
	}
	if (!stored || !buffer)
		return (NULL);
	str = (char *)malloc(ft_gnl_strlen(stored) + ft_gnl_strlen(buffer) + 1);
	if (str == NULL)
		return (NULL);
	i = -1;
	j = 0;
	if (stored)
		while (stored[++i] != '\0')
			str[i] = stored[i];
	while (buffer[j] != '\0')
		str[i++] = buffer[j++];
	str[ft_gnl_strlen(stored) + ft_gnl_strlen(buffer)] = '\0';
	free(stored);
	return (str);
}
