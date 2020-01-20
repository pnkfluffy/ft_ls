/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 17:32:01 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:28:08 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Allocates and returns an array of “fresh” strings obtained by spliting s
**	using the char c as a delimiter.
**	Example:
**	ft_strsplit("*hello*fellow***students*", ’*’)
**	Returns the array:
**	["hello", "fellow", "students"].
*/

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	wordend;
	size_t	x;
	char	**r;

	i = 0;
	x = 0;
	wordend = 0;
	if (!s)
		return (NULL);
	if (!(r = (char **)ft_memalloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] != c && s[i])
		{
			while (s[i + wordend] != c && s[i + wordend])
				wordend++;
			r[x++] = ft_strsub(s, i, wordend);
			i += wordend - 1;
			wordend = 0;
		}
		i++;
	}
	return (r);
}
