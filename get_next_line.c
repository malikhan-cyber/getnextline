/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alkhan <alkhan@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/08 14:47:07 by alkhan            #+#    #+#             */
/*   Updated: 2026/04/10 17:47:34 by alkhan           ###   ########.fr       */
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
int	find_newline(char **buffer, char **tempbuffer, int fd)
{
	char	*oud;
	int 	bytes_read;
	
	if (!*buffer)
		*buffer = ft_strdup("");
	if (!*buffer)
		return (-1);
	*tempbuffer = malloc(BUFFER_SIZE + 1);
	while ((ft_strchr(*buffer, SEARCH_CHAR)) == NULL)
	{
		bytes_read = read(fd, *tempbuffer, BUFFER_SIZE);
		if (bytes_read < 0)
			return (-1);
		if (bytes_read == 0)
			return(0);
		(*tempbuffer)[bytes_read] = '\0';
		oud = *buffer;
		*buffer = ft_strjoin(*buffer, *tempbuffer);
		free(oud);
		if (!*buffer)
			return (-1);
	}
	return(1);
}
char	*update_buffer(void)
{
}
char	*get_line(void)
{
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

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	find_newline(buffer, tempbuffer, fd);
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