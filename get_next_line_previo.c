/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 19:45:48 by mcarnere          #+#    #+#             */
/*   Updated: 2024/09/05 17:59:30 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//FIXME: quitar este include al terminar de debuggear 111111111111111111111111111111111111111111111111
#include <stdio.h>

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

char	*treat_line(int flag, char **leftover)
{
	if (flag == 0 && (!*leftover || **leftover == '\0'))
		return (NULL);
	if (flag < 0)
	{
		if (*leftover)
			free(*leftover);
		return (NULL);
	}
	return (*leftover);
}

static char	*read_next_line(int fd, char *leftover)
{
	char	*buffer;
	char	*aux;
	int		flag;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr_nwln(leftover))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag <= 0)
			break ;
		buffer[flag] = '\0';
		aux = leftover;
		leftover = ft_strjoin_tweaked(leftover, buffer);
		free(aux);
	}
	free(buffer);
	leftover = treat_line(flag, &leftover);
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
	//FIXME: usar flag para saber cuantos caracteres nos podemos mover
	aux = ft_strchr_nwln(leftover);
	if (aux)
	{
		offset = aux - leftover;
		ptr = ft_substr_tweaked(leftover, 0, offset);
		aux = leftover;
		leftover = ft_strdup(leftover + offset + 1);
		free(aux);
		return (ptr);
	}
	ptr = ft_strdup(leftover);
	free(leftover);
	leftover = NULL;
	return (ptr);
}
