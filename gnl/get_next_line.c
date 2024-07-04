/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:51:11 by mcarnere          #+#    #+#             */
/*   Updated: 2024/07/04 16:14:01 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Checks for the first occurrence of the character c in the string s
/// @param s String to search in
/// @param c Character to search for
/// @return Pointer to the found character, NULL if not found
char	*ft_strchr(const char *s, int c, int length)
{ 
	int	i;

	i = 0;
	while (i < length && *(s + i))
	{
		if (*(s + i) == (char) c)
			return ((char *) s + i);
		++i;
	}
	if ((char) c == '\0')
		return ((char *) s + i);
	return (NULL);
}

static char	*return_line(char *leftover, char *buffer, int flag)
{
	char	*ptr;

	if (flag < 0)
	{
		free(leftover);
		free(buffer);
		return (NULL);
	}
	leftover = ft_strjoin(leftover, buffer);
	free(buffer);
	if (flag == 0)
	{
		ptr = ft_strdup(leftover);
		free(leftover);
		return (ptr);
	}
	else
	{
		ptr = ft_strchr(leftover, '\n', ft_strlen(leftover));
		*ptr = '\0';
		ptr = ft_strdup(leftover);
		leftover = ft_strdup(ptr + 1);
		return (ptr);
	}
}

char	*get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	int			flag;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	flag = read(fd, buffer, BUFFER_SIZE);
	if (flag > 0)
		buffer[flag] = '\0';
	leftover = ft_strjoin(leftover, buffer);
	while (!ft_strchr(leftover, '\n', ft_strlen(leftover)) && flag > 0)
	{
		leftover = ft_strjoin(leftover, buffer);
		flag = read(fd, buffer, BUFFER_SIZE);
		buffer[flag] = '\0';
	}
	return (return_line(leftover, buffer, flag));
}
