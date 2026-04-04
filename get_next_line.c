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

char	*get_next_line(int fd)
{
	char	buffer[1024 + 1];
	ssize_t bytes;
	char	*ptr;
	int		len;
	char	*line;

	bytes = read(fd, buffer, 1024);
	if (bytes <= 0)
		return (NULL);
	buffer[bytes] = '\0';
	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
		return (NULL);
	len = (ptr - buffer) + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	memcpy(line, buffer, len);
	line[len] = '\0';
	return (line);
}

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("akjv.txt", O_RDONLY);
	line = get_next_line(fd);
	if (line)
	{
		printf("%s", line);
		free(line);
	}
	close(fd);
}
