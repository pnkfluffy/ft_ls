/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 12:35:05 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:28:58 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	man 3 strlen
*/

size_t	ft_strlen(const char *src)
{
	int i;

	i = 0;
	while (src[i] != '\0')
		i++;
	return (i);
}