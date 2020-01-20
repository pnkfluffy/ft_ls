/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replacechr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 04:44:50 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/08 23:37:15 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Takes a string and replaces all instances of char 'old' with char 'new'.
*/

char	*ft_replacechr(char *s, char old, char new)
{
	int i;

	i = -1;
	while (s[++i])
		if (s[i] == old)
			s[i] = new;
	return (s);
}
