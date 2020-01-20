/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fillstrnew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 13:18:21 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:29:59 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Allocates and returns a fresh string of 'width' length. The string is
**	populated entirely by char 'fill'.
*/

char	*ft_fillstrnew(int width, char fill)
{
	char	*str;
	int		i;

	if (width < 1)
		return (ft_strnew(0));
	i = -1;
	str = ft_strnew(width + 1);
	while (++i < width)
		str[i] = fill;
	return (str);
}
