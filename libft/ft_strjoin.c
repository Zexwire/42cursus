/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 15:11:06 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 19:20:35 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		size;
	char	*res;

	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = (char *) malloc(size * sizeof(char));
	ft_strlcpy(res, s1, size);
	ft_strlcat(res, s2, size);
	return (res);
}
