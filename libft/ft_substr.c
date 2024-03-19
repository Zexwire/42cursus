/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 18:03:43 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 16:52:59 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;

	res = (char *) malloc(len * sizeof(char));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, ft_strchr(s, start), len);
	return (res);
}
