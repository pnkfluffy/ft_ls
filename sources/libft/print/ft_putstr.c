/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 23:47:10 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:26:11 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Prints out given string to the standard output.
*/

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(1, &*s, ft_strlen(s));
}
