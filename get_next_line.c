/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:47:07 by alkhan            #+#    #+#             */
/*   Updated: 2026/04/10 16:39:15 by alkhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_gnl(char **buffer, char **tempbuffer)
{
	free(*buffer);
	free(*tempbuffer);
	*buffer = NULL;
	*tempbuffer = NULL;
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*tempbuffer;
	int			bytes_read;
	char		*ptr;
	char		*line;
	int			len;
	char		*rest;
	char		*oud;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!buffer)
		buffer = ft_strdup("");
	if (!buffer)
		return (NULL);
	tempbuffer = malloc(BUFFER_SIZE + 1);
	while ((ft_strchr(buffer, SEARCH_CHAR)) == NULL)
	{
		bytes_read = read(fd, tempbuffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (free_gnl(&buffer, &tempbuffer));
		if (bytes_read == 0)
			break ;
		tempbuffer[bytes_read] = '\0';
		oud = buffer;
		buffer = ft_strjoin(buffer, tempbuffer);
		free(oud);
		if (!buffer)
			return (NULL);
	}
	if ((bytes_read == 0) && (ft_strchr(buffer, SEARCH_CHAR) == NULL)
		&& (buffer[0] == '\0'))
		return (free_gnl(&buffer, &tempbuffer));
	ptr = ft_strchr(buffer, SEARCH_CHAR);
	if (ptr == NULL)
	{
		line = ft_strdup(buffer);
		if (!line)
			return (free_gnl(&buffer, &tempbuffer));
		free_gnl(&buffer, &tempbuffer);
		return (line);
	}
	len = (ptr - buffer) + 1;
	line = malloc(len + 1);
	if (!line)
		return (free_gnl(&buffer, &tempbuffer));
	ft_memcpy(line, buffer, len);
	line[len] = '\0';
	rest = ft_strdup(ptr + 1);
	if (!rest)
		return (free_gnl(&buffer, &tempbuffer));
	free(buffer);
	free(tempbuffer);
	buffer = rest;
	return (line);
}
/* int	main(void)
{
	int fd;
	char *line;

	fd = open("/dev/null", O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		printf("%s", line);
		if((ft_strchr(line, SEARCH_CHAR)) ==  NULL)
			break ;
		free(line);
	}
	close(fd);
	return (0);
} */