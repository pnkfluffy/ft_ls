/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 16:06:20 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:28:48 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	man 3 strncat
*/

char	*ft_strncat(char *dest, const char *src, size_t n)
{
	int i;
	int b;

	i = 0;
	b = 0;
	while (dest[i])
		i++;
	while (src[b] && n > 0)
	{
		dest[i + b] = src[b];
		b++;
		n--;
	}
	dest[i + b] = '\0';
	return (dest);
}
