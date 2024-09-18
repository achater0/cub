/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 18:40:06 by mstaali           #+#    #+#             */
/*   Updated: 2023/11/15 22:06:45 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t size)
{
	unsigned char	occ;
	unsigned char	*s;
	size_t			i;

	occ = (unsigned char)c;
	s = (unsigned char *)str;
	i = 0;
	while (i < size)
	{
		if (occ == s[i])
			return ((void *)&str[i]);
		i++;
	}
	return (NULL);
}
