/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/27 11:51:11 by mcarnere          #+#    #+#             */
/*   Updated: 2024/06/27 13:01:15 by mcarnere         ###   ########.fr       */
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

char *get_next_line(int fd)
{
	static char	*leftover;
	char		*buffer;
	int			flag;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer = (char *) malloc((BUFFER_SIZE + 1 )* sizeof(char));
	if (!buffer)
		return (NULL);
	flag = read(fd, buffer, BUFFER_SIZE);
	while (!ft_strchr(leftover, '\n') && flag > 0)
	{
		buffer[BUFFER_SIZE] = '\0';
		leftover = ft_strjoin(leftover, buffer);
		flag = read(fd, buffer, BUFFER_SIZE);
	}
	if (flag == 0)
	{
		//FIXME: saber si puedo devolver la estatica o si tengo que liberarla
		leftover = ft_strjoin(leftover, buffer);
		free(buffer);
		return (leftover);
	}
}
