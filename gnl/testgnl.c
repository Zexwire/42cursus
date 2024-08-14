/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testgnl.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 16:09:32 by mcarnere          #+#    #+#             */
/*   Updated: 2024/08/14 20:31:12 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

//TODO: casos de fd -1, fd aleatorio, y tener txts de prueba
int	main(void)
{
	int		fd;
	char	*line;

	fd = open("test.txt", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("\n%s\n\n", line);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);	
	return (0);
}
