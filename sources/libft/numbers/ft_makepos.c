/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makepos.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/25 14:17:41 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:25:50 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Returns a positive version of an long long int.
*/

int64_t		ft_makepos(int64_t a)
{
	if (a < 0)
		return (-a);
	return (a);
}
