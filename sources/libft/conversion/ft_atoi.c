/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:25:14 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:24:13 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	man 3 atoi
*/

int			ft_atoi(const char *str)
{
	int					i;
	int					sign;
	int					finalnum;

	i = 0;
	finalnum = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] && ft_isdigit(str[i]))
		finalnum = finalnum * 10 + (str[i++] - '0');
	return (finalnum * sign);
}
