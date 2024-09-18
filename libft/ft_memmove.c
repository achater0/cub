/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 17:10:26 by mstaali           #+#    #+#             */
/*   Updated: 2023/11/20 23:07:35 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t size)
{
	char		*d;
	const char	*s;

	d = (char *)dest;
	s = (const char *)src;
	if (size == 0)
		return (dest);
	if (d > s && d < (char *)s + size)
	{
		while (size--)
			*(char *)(dest + size) = *(char *)(src + size);
	}
	else
		ft_memcpy(dest, src, size);
	return (dest);
}
