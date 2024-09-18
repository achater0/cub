/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 21:42:05 by mstaali           #+#    #+#             */
/*   Updated: 2023/11/15 21:06:38 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t size)
{
	unsigned char	*s1;
	unsigned char	*s2;
	int				diff;

	s1 = (unsigned char *)str1;
	s2 = (unsigned char *)str2;
	while (size > 0)
	{
		diff = (int)(*s1) - (int)(*s2);
		if (diff != 0)
			return (diff);
		s1++;
		s2++;
		size--;
	}
	return (0);
}
