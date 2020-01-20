/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:06:33 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:25:09 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Takes as a parameter the address of a memory area that needs
**	to be freed with, frees it, then puts the pointer to NULL.
*/

void	ft_memdel(void **ap)
{
	free(*ap);
	*ap = NULL;
}
