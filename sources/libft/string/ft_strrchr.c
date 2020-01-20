/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/28 02:25:02 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/29 17:02:28 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	man 3 strrchr
*/

char	*ft_strrchr(const char *str, int c)
{
	int i;

	i = ft_strlen(str);
	if (!c)
		return ((char *)&str[i]);
	while (--i >= 0)
		if (str[i] == c)
			return ((char *)&str[i]);
	return (NULL);
}
