/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/04 11:34:23 by alkhan            #+#    #+#             */
/*   Updated: 2026/04/05 13:14:43 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	j;
	char	*ptr;

	j = 0;
	if (start >= ft_strlen(s))
	{
		ptr = malloc(1);
		if (!ptr)
			return (0);
		ptr[0] = '\0';
		return (ptr);
	}
	if (len > ft_strlen(&s[start]))
		ptr = malloc(ft_strlen(&s[start]) + 1);
	else
		ptr = malloc(len + 1);
	if (!ptr)
		return (0);
	while (s[start + j] && j < len)
	{
		ptr[j] = s[start + j];
		j++;
	}
	ptr[j] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *str, int c)
{
	int				i;
	int				result;
	unsigned char	cc;

	cc = (unsigned char)c;
	i = 0;
	result = 0;
	while (str[i] && str[i] != cc)
		i++;
	if (str[i] == '\0' && cc != '\0')
		return (0);
	result = i;
	return ((char *)(str + result));
}

char	*ft_strdup(const char *str)
{
	int		i;
	char	*ptr;

	i = 0;
	while (str[i])
		i++;
	ptr = malloc((i + 1) * sizeof(char));
	i = 0;
	if (ptr == 0)
		return (0);
	while (str[i])
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		len;
	char	*ptr;

	len = (ft_strlen(s1) + ft_strlen(s2));
	ptr = malloc(len + 1);
	if (ptr == 0)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		ptr[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ptr[i] = s2[j];
		i++;
		j++;
	}
	ptr[i] = '\0';
	return (ptr);
}

size_t	ft_strlen(const char *c)
{
	int	i;

	i = 0;
	while (c[i])
		i++;
	return (i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*cdest;
	unsigned char	*csrc;

	csrc = (unsigned char *)src;
	cdest = (unsigned char *)dest;
	if (dest == 0 && src == 0)
		return (dest);
	i = 0;
	while (i < n)
	{
		cdest[i] = csrc[i];
		i++;
	}
	return (dest);
}