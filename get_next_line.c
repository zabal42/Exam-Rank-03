/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mikelzabal <mikelzabal@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/25 19:26:32 by mikelzabal        #+#    #+#             */
/*   Updated: 2025/03/26 14:19:41 by mzabal-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	char	*buffer;
	char	c;
	int		bytes;
	int		i;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	i = 0;
	while ((bytes = read(fd, &c, 1)) > 0)
	{
		buffer[i++] = c;
		if (BUFFER_SIZE > 0 && i % BUFFER_SIZE == 0)
		{
			char *new_buffer = malloc(i + BUFFER_SIZE + 1);
			if (!new_buffer)
				return (free(buffer), NULL);
			int j = 0;
			while (j < i)
			{
				new_buffer[j] = buffer[j];
				j++;
			}
			free(buffer);
			buffer = new_buffer;
		}
		if (c == '\n')
			break ;
	}
	if (i == 0 || bytes < 0)
	{
		free(buffer);
		return (NULL);
	}
	buffer[i] = '\0';
	return (buffer);
}

