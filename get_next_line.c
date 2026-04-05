/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/01 15:57:17 by alkhan            #+#    #+#             */
/*   Updated: 2026/04/05 13:14:51 by marvin           ###   ########.fr       */
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
	int	count;
	int	i;
	
	i = 0;
	count = 0;
	buffer = malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return(NULL);
	bytes = read(fd, buffer, BUFFER_SIZE);
	if (bytes <= 0)
		return (NULL);
	printf("\nbytes read is: %ld\n",bytes);
	printf("\nbuffer contains:\n\n%s\n\n", buffer);
	buffer[bytes] = '\0';
	while(buffer[i])
	{
		if(buffer[i] == '\n')
		{
			count++;
			printf("new line on: %d\n", i);
		}
		i++;
	}
	printf("\nbuffer still contains:\n\n%s\n\n",buffer);
	printf("\nnew lines counted: %d\n",count);
	ptr = strchr(buffer, '\n');
	if (!ptr)
		return (NULL);
	printf("\nptr is: \n%s\n\n",ptr);
	len = (ptr - buffer) + 1;
	printf("\nreturn length is: %d\n",len);
	line = malloc(len + 1);
	if (!line)
		return (NULL);
	printf("\nreturn line is: %s\n",(char *)ft_memcpy(line, buffer, len));
	line[len] = '\0';
	return (line);
}
 
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while(line)
	{
		line = get_next_line(fd);
		if(!line)
			break ;
		printf("%s", line);
		free(line);
	} 
//	if (line)
//	{
//		printf("%s", line);
//		free(line);
//	}
	close(fd);
}
