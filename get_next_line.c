/* ************************************************************************** */
/*                                                                            */
/*                                                         ::::::::           */
/*   get_next_line.c                                     :+:    :+:           */
/*                                                      +:+                   */
/*   By: alkhan <marvin@42.fr>                         +#+                    */
/*                                                    +#+                     */
/*   Created: 2026/04/01 15:57:17 by alkhan         #+#    #+#                */
/*   Updated: 2026/04/03 16:49:02 by alkhan         ########   odam.nl        */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>
#define BUFFER_SIZE 1024

/* 
char	*return_str(void)
{
	static char *str;
} */
char	*get_next_line(int fd)
{
	char	*buffer;
	ssize_t	bytes;
	char	*ptr;
	int		len;
	char	*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return(NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	buffer[bytes] = '\0';
	ptr = strchr(buffer, '\n');
	if (!ptr)
		return (NULL);
	len = (ptr - buffer) + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	ft_memcpy(line, buffer, len);
	line[len] = '\0';
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("akjv.txt", O_RDONLY);
	line = get_next_line(fd);
/* 		while(line)
		{
			line = get_next_line(fd);
			if(!line)
				break ;
			printf("%s", line);
			free(line);
		} */
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
