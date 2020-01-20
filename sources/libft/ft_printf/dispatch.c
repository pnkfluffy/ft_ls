/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jfelty <jfelty@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:14:15 by jfelty            #+#    #+#             */
/*   Updated: 2019/11/09 20:22:20 by jfelty           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		get_choice(t_format *format, va_list args)
{
	if (format->type == 'c' || format->type == '%')
		return (format_c(format, args));
	else if (format->type == 's')
		return (format_s(format, args));
	else if (format->type == 'p')
		return (format_p(format, args));
	else if (format->type == 'i' || format->type == 'd')
		return (format_di(format, args));
	else if (format->type == 'o')
		return (format_o(format, args));
	else if (format->type == 'u')
		return (format_u(format, args));
	else if (format->type == 'x' || format->type == 'X')
		return (format_xx(format, args));
	else if (format->type == 'f')
		return (format_f(format, args));
	else
		return (-1);
}

int		dispatch(t_print *print, va_list args)
{
	t_format		*format;
	int				choice;

	format = print->fmts;
	while (format)
	{
		if ((choice = get_choice(format, args)) < 0)
			return (format->type);
		format = format->next;
	}
	return (0);
}

int		get_format(char *str, char **fmt)
{
	char	*end;

	end = str;
	while (!(ft_strchr(PFCONV, *end)))
		end++;
	end++;
	*fmt = ft_strnew(end - str);
	ft_strncpy(*fmt, str, end - str);
	return (end - str + 1);
}
