/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 19:51:12 by mcarnere          #+#    #+#             */
/*   Updated: 2024/09/17 00:01:15 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_substr_tweaked(char const *s, unsigned int start, size_t len);
char	*ft_strjoin_tweaked(char const *s1, char const *s2);
char	*ft_strchr_nwln(const char *s);
char	*ft_strdup(const char *s1);
size_t	ft_strlen(const char *s);

#endif