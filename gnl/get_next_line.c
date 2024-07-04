/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:51:50 by mcarnere          #+#    #+#             */
/*   Updated: 2024/07/04 21:50:40 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

/// @brief Checks for the first occurrence of the character c in the string s
/// @param s String to search in
/// @param c Character to search for
/// @return Pointer to the found character, NULL if not found
static char	*ft_strchr(const char *s, int c)
{
	int		i;

	if (s)
	{
		i = 0;
		while (*(s + i))
		{
			if (*(s + i) == (char) c)
				return ((char *) s + i);
			++i;
		}
	}
	if ((char) c == '\0')
		return ((char *) s + i);
	return (NULL);
}

int	read_next_line(int fd, char *leftover)
{
	char	*buffer;
	char	*aux;
	int		flag;

	buffer = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	while (!ft_strchr(leftover, '\n'))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag <= 0)
			break ;
		buffer[flag] = '\0';
		aux = leftover;
		leftover = ft_strjoin(leftover, buffer);
		free(aux);
	}
	free(buffer);
	if (flag < 0)
		free(leftover);
	return (flag);
}

char	*get_next_line(int fd)
{
	static char	*leftover = NULL;
	char		*ptr;
	char		*aux;
	int			flag;

	if (BUFFER_SIZE <= 0 || fd < 0)
	//FIXME: no se si liberar leftover aquí
		return (NULL);
	flag = read_next_line(fd, leftover);
	if (flag < 0)
		return (NULL);
	if (flag == 0)
	{
		ptr = ft_strdup(leftover);
		free(leftover);
		return (ptr);
	}
	//FIXME: comprobar si necesita un +1
	flag = ft_strchr(leftover, '\n') - leftover;
	ptr = ft_substr(leftover, 0, flag);
	aux = leftover;
	leftover = ft_strdup(leftover + flag);
	free(aux);
	return (ptr);
}
