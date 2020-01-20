/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:00:15 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:28:05 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Allocates (with malloc(3)) and returns a “fresh” substring
**	from the string given as argument. The substring begins at
**	indexstart and is of size len. If start and len aren’t refering
**	to a valid substring, the behavior is undefined. If the
**	allocation fails, the function returns NULL.
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;

	if (s && (substr = (char *)ft_memalloc(sizeof(char) * len + 1)))
	{
		i = 0;
		while (i < len)
		{
			substr[i] = s[i + start];
			i++;
		}
		substr[i] = '\0';
		return (substr);
	}
	return (NULL);
}
