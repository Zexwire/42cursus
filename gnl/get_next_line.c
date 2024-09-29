/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:30:37 by mcarnere          #+#    #+#             */
/*   Updated: 2024/09/29 20:33:11 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*free_holded(char **in_hold)
{
	free(*in_hold);
	*in_hold = NULL;
	return (NULL);
}

static void	update_holded(char *in_hold)
{
	char	*nwln;
	char	*aux;
	size_t	start;

	nwln = ft_strchr_nwln(in_hold);
	if (!nwln)
	{
		free_holded(&in_hold);
		return ;
	}
	aux = in_hold;
	start = nwln - in_hold + 1;
	in_hold = ft_substr_tweaked(in_hold, start, ft_strlen(in_hold) - start);
	free(aux);
	return ;
}

static char	*extract_line(char *in_hold)
{
	char	*res;
	char	*aux;
	int		offset;

	aux = ft_strchr_nwln(in_hold);
	if (!aux)
	{
		res = ft_strdup(in_hold);
		free_holded(&in_hold);
		return (res);
	}
	offset = aux - in_hold + 1;
	res = ft_substr_tweaked(in_hold, 0, offset);
	if (!res)
		return (NULL);
	return (res);
}

static void	read_file(char *in_hold, int fd)
{
	char	*buffer;
	char	*aux;
	int		flag;

	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	buffer[0] = '\0';
	while (!ft_strchr_nwln(in_hold))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag <= 0)
			break ;
		buffer[flag] = '\0';
		aux = ft_strjoin_tweaked(in_hold, buffer);
		free(in_hold);
		in_hold = aux;
		free(aux);
		if (!in_hold)
			return ;
	}
	free(buffer);
	if (flag < 0)
		free_holded(&in_hold);
}

char	*get_next_line(int fd)
{
	static char	*in_hold = NULL;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!in_hold || !ft_strchr_nwln(in_hold))
		read_file(in_hold, fd);
	if (!in_hold)
		return (free_holded(&in_hold));
	res = extract_line(in_hold);
	if (!res)
		return (free_holded(&in_hold));
	update_holded(in_hold);
	return (res);
}
