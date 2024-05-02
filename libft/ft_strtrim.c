/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcarnere <mcarnere@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:35:29 by mcarnere          #+#    #+#             */
/*   Updated: 2024/05/02 17:31:04 by mcarnere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/// @brief Check if a character is in a set
/// @param c Character to check
/// @param set Set of characters
/// @return 0 if not in set, 1 if in set
static int	set_contains(char c, char const *set)
{
	int	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		++i;
	}
	return (0);
}

/// @brief Deletes the set of characters from the beginning and end of a string
/// @param s1 String to trim
/// @param set Characters to trim
/// @return Pointer to the allocated trimmed string
char	*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		j;
	char	*res;

	if (*s1 == '\0')
		return (ft_strdup(""));
	i = 0;
	while (set_contains(*(s1 + i), set))
		++i;
	j = ft_strlen(s1) - 1;
	while (set_contains(*(s1 + j), set))
		--j;
	if (i > j)
		return (ft_strdup(""));
	res = ft_substr(s1, i, (j - i + 1));
	if (res == NULL)
		return (NULL);
	return (res);
}
