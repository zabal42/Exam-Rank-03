/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzabal-m <mzabal-m@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/24 13:37:59 by mzabal-m          #+#    #+#             */
/*   Updated: 2025/03/24 13:56:30 by mzabal-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 42
#endif

char	*get_next_line(int fd)
{
	int		byte;
	int		i = 0;
	char	c;
	char	*str_buffer;

	if (BUFFER_SIZE < 1 || fd < 0)
		return (NULL);
	str_buffer = (char*)malloc(10000000);
	if (!str_buffer)
		return (NULL);
	byte = read(fd, &c, 1);
	while (byte > 0)
	{
		str_buffer[i++] = c;
		if (c== '\n')
			break;
		byte = read (fd, &c, 1);
	}
	if (i == 0 || byte < 0)
	{
		free(str_buffer);
		return (NULL);
	}
	str_buffer[i] = '\0';
	return (str_buffer);
}
