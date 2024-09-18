/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achater <achater@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 22:19:47 by mstaali           #+#    #+#             */
/*   Updated: 2024/09/17 15:47:01 by achater          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	s_len;

	s_len = 0;
	while (size && src[s_len] && s_len < size - 1)
	{
		if (src[s_len] == ' ' || src[s_len] == '\t')
			dest[s_len] = '5';
		else
			dest[s_len] = src[s_len];
		s_len++;
	}
	if (size > 0)
		dest[s_len] = '\0';
	while (src[s_len])
		s_len++;
	return (s_len);
}
