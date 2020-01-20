/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_to_str_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:18:27 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:29:46 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Allocates and returns a fresh string made from pushing the character c to
**	the beginning of the string passed in as an argument. Deletes the old
**	string.
*/

char		*ft_push_to_str_front(char *str, char c)
{
	char	*ret;
	int		i;

	i = 0;
	ret = ft_memalloc(sizeof(char) * (ft_strlen(str) + 2));
	ret[i] = c;
	while (str[i])
	{
		ret[i + 1] = str[i];
		i++;
	}
	ret[i + 1] = '\0';
	ft_strdel(&str);
	return (ret);
}
