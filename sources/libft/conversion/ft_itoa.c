/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:30:21 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/25 19:24:01 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

/*
**	Takes an int value and returns a "fresh" string represeinting the int.
*/

char	*ft_itoa(int n)
{
	char	*str;
	int		i;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = ft_numlen(n) - 1;
	if (!(str = (char *)malloc(sizeof(char) * ft_numlen(n) + 1)))
		return (NULL);
	str[i + 1] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		n *= -1;
	}
	while (n > 9)
	{
		str[i--] = n % 10 + '0';
		n /= 10;
	}
	str[i] = n + '0';
	return (str);
}
