/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:45:48 by mcarnere          #+#    #+#             */
/*   Updated: 2024/08/14 20:41:59 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

/// @brief Length of a string
/// @param s String to measure
/// @return Length of the string
size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

/// @brief Tweaked versión of strchr to only check for newline
/// @param s String to search in
/// @return Pointer to the found newline, NULL if not found
static char	*ft_strchr_nwln(const char *s)
{
	int	i;

	if (!s)
		return (NULL);
	i = 0;
	while (*(s + i))
	{
		if (*(s + i) == '\n')
			return ((char *) s + i);
		++i;
	}
	return (NULL);
}

static char	*read_next_line(int fd, char *leftover)
{
	char	*buffer;
	char	*aux;
	int		flag;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	flag = 1;
	while (flag > 0 && !ft_strchr_nwln(leftover))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		buffer[flag] = '\0';
		aux = leftover;
		leftover = ft_strjoin(leftover, buffer);
		printf("Variables accessible from here: \nFlag: %d\nLeftover: %s\nAux: %s\n", flag, leftover, aux);
		//este free da error de doble liberación, pero no sé porque
		free(aux);
	}
	free(buffer);
	if (flag < 0)
	{
		if (leftover)
			free(leftover);
		return (NULL);
	}
	return (leftover);
}

char	*get_next_line(int fd)
{
	
	static char	*leftover = NULL;
	char		*ptr;
	char		*aux;
	int			offset;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	if (!ft_strchr_nwln(leftover))
		leftover = read_next_line(fd, leftover);
	if (!leftover)
		return (NULL);
	aux = ft_strchr_nwln(leftover);
	if (aux)
	{
		offset = aux - leftover;
		ptr = ft_substr(leftover, 0, offset);
		aux = leftover;
		leftover = ft_strdup(leftover + offset + 1);
		printf("PITO Y BOLAS\nVariables accessible from here: \nOffset: %d\nLeftover: %s\nAux: %s\n", offset, leftover, aux);
		if (!leftover)
			return (NULL);
		free(aux);
		return (ptr);
	}
	return (leftover);
}
