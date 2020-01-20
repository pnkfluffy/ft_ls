/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wordcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 20:22:02 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:27:54 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Returns the number of words from an input string as seperated by the
**	delimiter 'c'.
*/

int	ft_wordcount(char const *s, char c)
{
	int i;
	int numwords;

	numwords = 0;
	i = 0;
	if (s[i] != c)
		numwords++;
	while (s[i])
	{
		if (s[i] != c && s[i - 1] == c)
			numwords++;
		i++;
	}
	return (numwords);
}
