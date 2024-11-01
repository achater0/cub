/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mstaali <mstaali@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/10 10:58:19 by mstaali           #+#    #+#             */
/*   Updated: 2024/10/19 17:05:26 by mstaali          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

char	*extract_line(char *stored)
{
	int		i;
	char	*str;

	i = 0;
	if (!stored[i])
		return (NULL);
	while (stored[i] && stored[i] != '\n')
		i++;
	str = (char *)malloc(i + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (stored[i] && stored[i] != '\n')
	{
		str[i] = stored[i];
		i++;
	}
	if (stored[i] == '\n')
	{
		str[i] = stored[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*clean_last_line(char *stored)
{
	int		i;
	int		j;
	char	*clean;

	i = 0;
	while (stored[i] && stored[i] != '\n')
		i++;
	if (!stored[i])
	{
		free(stored);
		return (NULL);
	}
	clean = (char *)malloc(ft_gnl_strlen(stored) - i + 1);
	if (!clean)
		return (NULL);
	i++;
	j = 0;
	while (stored[i])
		clean[j++] = stored[i++];
	clean[j] = '\0';
	free(stored);
	return (clean);
}

char	*read_and_store(int fd, char *stored)
{
	char	*buffer;
	int		readed;

	buffer = (char *)malloc((size_t)BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	readed = 1;
	while (!ft_gnl_strchr(stored, '\n') && readed != 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[readed] = '\0';
		stored = ft_gnl_strjoin(stored, buffer);
	}
	free(buffer);
	return (stored);
}

char	*get_next_line(int fd)
{
	static char	*stored;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
	{
		free(stored);
		stored = NULL;
		return (NULL);
	}
	stored = read_and_store(fd, stored);
	if (!stored)
		return (NULL);
	line = extract_line(stored);
	stored = clean_last_line(stored);
	return (line);
}
