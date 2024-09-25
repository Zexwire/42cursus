/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/16 22:30:37 by mcarnere          #+#    #+#             */
/*   Updated: 2024/09/17 00:13:59 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*free_holded(char *in_hold)
{
	free(in_hold);
	in_hold = NULL;
	return (NULL);	
}

static char	*update_holded(char *in_hold)
{
	char	*aux;
	
	if (!ft_strchr_nwln(in_hold))
		return (free_holded(in_hold));
	aux = in_hold;
	//TODO: termianr la función
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
		free_holded(in_hold);
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
	while (!ft_strchr_nwln(in_hold))
	{
		flag = read(fd, buffer, BUFFER_SIZE);
		if (flag <= 0)
			break ;
		buffer[flag] = '\0';
		aux = in_hold;
		in_hold = ft_strjoin_tweaked(in_hold, buffer);
		free(aux);
		if (!in_hold)
			return ;
	}
	free(buffer);
	if (flag < 0)
		free_holded(in_hold);
}

char	*get_next_line(int fd)
{
	static char	*in_hold = NULL;
	char		*res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (!in_hold || !ft_strchr_nwln(in_hold))
	//TODO: puede que tenga que pasar con & para que se guarde, idk
		read_file(in_hold, fd);
	if (!in_hold)
		return (free_holded(in_hold));
	res = extract_line(in_hold);
	if (!res)
		return (free_holded(in_hold));
	update_holded(in_hold);
	return (res);
}
