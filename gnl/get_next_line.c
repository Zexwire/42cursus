/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:51:11 by mcarnere          #+#    #+#             */
/*   Updated: 2024/07/04 12:13:06 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/// @brief Checks for the first occurrence of the character c in the string s
/// @param s String to search in
/// @param c Character to search for
/// @return Pointer to the found character, NULL if not found
char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == (char) c)
			return ((char *) s + i);
		++i;
	}
	if ((char) c == '\0')
		return ((char *) s + i);
	return (NULL);
}

char	*select(char *leftover, char *buffer, int flag)
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
		//FIXME: lo ha hecho Copilot, comprobarlo bien
		ptr = ft_strchr(leftover, '\n');
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
	while (!ft_strchr(leftover, '\n') && flag > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		leftover = ft_strjoin(leftover, buffer);
		flag = read(fd, buffer, BUFFER_SIZE);
	}
	return (select(leftover, buffer, flag));
}
