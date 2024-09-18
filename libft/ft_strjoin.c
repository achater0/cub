/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 16:36:04 by mstaali           #+#    #+#             */
/*   Updated: 2023/11/23 10:22:02 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buffer;
	char	*b;
	size_t	total_len;

	if (!s1 || !s2)
		return (NULL);
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	buffer = (char *)malloc(total_len);
	if (!buffer)
		return (NULL);
	b = buffer;
	while (*s1)
		*b++ = *s1++;
	while (*s2)
		*b++ = *s2++;
	*b = '\0';
	return (buffer);
}
