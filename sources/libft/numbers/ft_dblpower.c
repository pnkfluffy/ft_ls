/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dblpower.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 19:21:26 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:21:58 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

double		ft_dblpower(double num, int pow)
{
	int		i;
	double	ret;

	i = 0;
	ret = num;
	if (pow == 0)
		return (1);
	while (++i < pow)
		ret *= num;
	return (ret);
}
