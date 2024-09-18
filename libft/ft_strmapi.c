/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/11 16:32:04 by mstaali           #+#    #+#             */
/*   Updated: 2023/11/27 17:29:44 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*buffer;
	size_t	i;

	if (!s || !f)
		return (NULL);
	buffer = (char *)malloc(ft_strlen(s) + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while (s[i])
	{
		buffer[i] = f((unsigned int)i, s[i]);
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
