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

char	*ft_findnewline(int fd, char *buffer)
{
	char	*line;
	int		i;
	int		j;
	char	*temp_buffer;

	i = 0;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
		{
			while (j <= i)
				line[j] = buffer[j];
		}
		else
		{
			buffer = malloc(BUFFER_SIZE + 1);
			if (!buffer)
				return (NULL);
			buffer = buffer + (read(fd, buffer, BUFFER_SIZE));
		}
		i++;
	}
	return (line);
}
char	*get_next_line(int fd)
{
	static char	*buffer;
	ssize_t		bytes;
	char		*ptr;
	int			len;
	char		*line;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	if (bytes < BUFFER_SIZE)
		// laatste gedeelte van tekst bereikt
		buffer[bytes] = '\0';
	if (ft_findnewline(fd, buffer) == 0)
		return ("no new line found, but run ");
	ptr = ft_strchr(buffer, '\n');
	if (!ptr)
		return (NULL);
	len = (ptr - buffer) + 1;
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	line[len] = '\0';
	return (line = ft_memcpy(line, buffer, len));
}

int	main(void)
{
	int fd;
	char *line;

	fd = open("testbestand2.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
	}
	/* if (line)
	{
		printf("%s", line);
		free(line);
	} */
	close(fd);
}