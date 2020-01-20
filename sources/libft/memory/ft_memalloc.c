/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:41:04 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:25:21 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Allocates and returns a “fresh” memory area. The memory allocated is
**	initialized to 0. If the allocation fails, the function returns NULL.
*/

void	*ft_memalloc(size_t n)
{
	void *s;

	if (!(s = malloc(n)))
		return (NULL);
	ft_bzero(s, n);
	return (s);
}
