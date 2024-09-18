/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbl_strlen.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/17 14:03:26 by mstaali           #+#    #+#             */
/*   Updated: 2024/09/17 14:06:46 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_dbl_strlen(char **str)
{
	size_t	count;

	if (!str || !*str)
		return (0);
	count = 0;
	while (str[count])
		count++;
	return (count);
}
