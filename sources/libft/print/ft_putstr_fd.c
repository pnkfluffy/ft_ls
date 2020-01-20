/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 00:24:27 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:26:15 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Prints out given string to the given file descriptor.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return ;
	write(fd, &*s, ft_strlen(s));
}
