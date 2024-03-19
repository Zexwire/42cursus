/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:29 by mcarnere          #+#    #+#             */
/*   Updated: 2024/03/19 16:57:07 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	set_contains(char const *ptr, char const *set)
{
	char	*set_ptr;

	set_ptr = set;
	while (set_ptr)
	{
		if (set_ptr == ptr)
			return (1);
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*start_ptr;
	char	*end_ptr;
	char	*res;
	char	*res_ptr;

	start_ptr = s1;
	while (set_contains(start_ptr, set))
		++start_ptr;
	end_ptr = s1 + ft_strlen(s1) - 1;
	while (set_contains(end_ptr, set))
		--end_ptr;
	res = malloc((end_ptr - start_ptr) * sizeof(char));
	if (res == NULL)
		return (NULL);
	res_ptr = res;
	while (start_ptr != end_ptr)
	{
		res_ptr = start_ptr;
		++res_ptr;
		++start_ptr;
	}
	res_ptr = start_ptr;
	return (res);
}
