/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:41:57 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:28:35 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Lexicographical comparison between s1 and s2 up to n characters or until a
**	’\0’ is reached. If the 2 strings are identical, the function returns 1,
**	or 0 otherwise.
*/

int	ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if (s1 && s2 && n)
		return (ft_strncmp(s1, s2, n) == 0);
	if (!(n))
		return (1);
	return (0);
}
